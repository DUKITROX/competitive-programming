#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

struct UAV {
    int x,y;
    double B;
    int phi;
};

struct Flow {
    int id;
    int ax, ay;
    int t_start;
    double s; 
    int m1, n1, m2, n2;
};

struct Assign {
    int t;
    int x, y;
    double z;
};

int M, N, FN, T;
vector<vector<UAV>> uav;
vector<Flow> flows;
double eps = 1e-9;

// capacity remaining per UAV per time (Mbps)
vector<vector<vector<double>>> cap_remain; // [M][N][T]
vector<vector<vector<double>>> bval; // precomputed capacity b(x,y,t)

inline double bandwidth_at(const UAV &u, int t) {
    int idx = (u.phi + t) % 10;
    if (idx <= 1 || idx >= 8) return 0.0;
    if (idx == 2 || idx == 7) return u.B / 2.0;
    return u.B;
}

double delta_dist = 0.1; // default in problem

vector<vector<Assign>> solution; // size FN

inline int hops(int ax, int ay, int x, int y) {return abs(ax - x) + abs(ay - y);}

// compute global weighted score (we multiply flowScore by flow.s to get weighted objective)
double compute_weighted_score(const vector<vector<Assign>>& sol) {
    double total_weighted = 0.0;
    for (int i = 0; i < FN; ++i) {
        const Flow &f = flows[i];
        const auto &assigns = sol[i];
        double transmitted = 0.0;
        for (auto &a : assigns) transmitted += a.z; // Mbps for 1 second => Mbits
        // transmitted is sum of Mbps per second over each second (units Mbits)
        double totalU2GScore = (f.s <= 0 ? 0.0 : min(1.0, transmitted / f.s));
        // delay score
        double delayScore = 0.0;
        for (auto &a : assigns) {
            int trel = a.t - f.t_start;
            if (trel < 0) trel = 0;
            double frac = (f.s > 0 ? (a.z / f.s) : 0.0);
            delayScore += (10.0 / (trel + 10.0)) * frac;
        }
        // distance score
        double distanceScore = 0.0;
        for (auto &a : assigns) {
            int h = hops(f.ax, f.ay, a.x, a.y);
            double frac = (f.s > 0 ? (a.z / f.s) : 0.0);
            distanceScore += frac * pow(2.0, -h * delta_dist);
        }
        // landing UAV point score
        double landingScore = 0.0;
        if (assigns.empty()) {
            landingScore = 0.0;
        } else {
            // sort by time and count changes
            vector<Assign> v = assigns;
            sort(v.begin(), v.end(), [](const Assign &a, const Assign &b){ return a.t < b.t; });
            int k = 1;
            for (size_t ii = 1; ii < v.size(); ++ii) {
                if (v[ii].x != v[ii-1].x || v[ii].y != v[ii-1].y) ++k;
            }
            landingScore = 1.0 / double(k);
        }
        double flowScore = 100.0 * (0.4 * totalU2GScore + 0.2 * delayScore + 0.3 * distanceScore + 0.1 * landingScore);
        total_weighted += flowScore * f.s; // weight by flow size to match weighted total logic
    }
    return total_weighted;
}

// Helper to remove a flow's assignments from cap_remain (refund capacities)
void refund_flow_caps(int idx, vector<vector<Assign>>& sol, vector<vector<vector<double>>> &caps) {
    for (auto &a : sol[idx]) {
        caps[a.x][a.y][a.t] += a.z;
    }
    sol[idx].clear();
}

// Greedy randomized reassign for one flow (fills as much as possible)
void randomized_assign_flow(int idx, vector<vector<Assign>>& sol, vector<vector<vector<double>>> &caps, std::mt19937 &rng) {
    Flow &f = flows[idx];
    double rem = f.s;
    // iterate time from start to T-1
    uniform_real_distribution<double> unif(0.0, 1.0);
    for (int t = f.t_start; t < T && rem > 1e-6; ++t) {
        // collect candidate UAVs in rectangle
        struct Candidate { int x,y; double score; double cap; int h; };
        vector<Candidate> cand;
        for (int x = f.m1; x <= f.m2; ++x) for (int y = f.n1; y <= f.n2; ++y) {
            if (x<0||x>=M||y<0||y>=N) continue;
            double cap = caps[x][y][t];
            if (cap <= 1e-9) continue;
            int h = hops(f.ax, f.ay, x, y);
            // heuristic score: capacity * distance factor * randomness
            double dist_factor = pow(2.0, -h * delta_dist);
            double noise = 0.9 + 0.2 * unif(rng); // random in [0.9,1.1]
            double sc = cap * dist_factor * noise;
            cand.push_back({x,y,sc,cap,h});
        }
        if (cand.empty()) continue;
        // choose candidate by weighted score
        double sumsc = 0.0;
        for (auto &c : cand) sumsc += c.score;
        double pick = unif(rng) * sumsc;
        double cum = 0.0;
        int chosen = 0;
        for (size_t i=0;i<cand.size();++i) { cum += cand[i].score; if (pick <= cum) { chosen = i; break; } }
        Candidate c = cand[chosen];
        // allocate amount
        double z = min(rem, c.cap);
        if (z <= 1e-9) continue;
        // consume capacity
        caps[c.x][c.y][t] -= z;
        // record assignment
        sol[idx].push_back({t, c.x, c.y, z});
        rem -= z;
    }
    // If still remaining and unable to allocate due to capacity, we simply leave unsent remainder (affects totalU2GScore)
}

// Build initial greedy solution (deterministic)
void build_initial_solution(vector<vector<Assign>>& sol, vector<vector<vector<double>>> &caps) {
    // Process flows in input order
    for (int i=0;i<FN;++i) {
        Flow &f = flows[i];
        double rem = f.s;
        for (int t = f.t_start; t < T && rem > 1e-6; ++t) {
            // pick UAV with maximum cap * distanceFactor
            double bestScore = -1.0;
            int bx=-1, by=-1;
            for (int x = f.m1; x <= f.m2; ++x) for (int y = f.n1; y <= f.n2; ++y) {
                if (x<0||x>=M||y<0||y>=N) continue;
                double cap = caps[x][y][t];
                if (cap <= 1e-9) continue;
                int h = hops(f.ax, f.ay, x, y);
                double factor = pow(2.0, -h * delta_dist);
                double sc = cap * factor;
                if (sc > bestScore) { bestScore = sc; bx=x; by=y; }
            }
            if (bestScore < 0) continue;
            double z = min(rem, caps[bx][by][t]);
            if (z <= 1e-9) continue;
            caps[bx][by][t] -= z;
            sol[i].push_back({t, bx, by, z});
            rem -= z;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> M >> N >> FN >> T
    uav.assign(M, vector<UAV>(N));

    for (int i=0;i<M*N;++i) {
        int x,y,phi; double B;
        cin >> x >> y >> B >> phi;

        uav[x][y].B = B;
        uav[x][y].phi = phi;
    }
    flows.clear();
    for (int i=0;i<FN;++i) {
        Flow f;
        int id, x,y, tstart, s, m1,n1,m2,n2;
        cin >> id >> x >> y >> tstart >> s >> m1 >> n1 >> m2 >> n2;
        f.id = id;
        f.ax = x; f.ay = y;
        f.t_start = tstart;
        f.s = s;
        f.m1 = m1; f.n1 = n1; f.m2 = m2; f.n2 = n2;
        flows.push_back(f);
    }

    // Precompute bval for each UAV/time and initialize cap_remain
    bval.assign(M, vector<vector<double>>(N, vector<double>(T, 0.0)));
    cap_remain.assign(M, vector<vector<double>>(N, vector<double>(T, 0.0)));
    for (int x=0;x<M;++x) for (int y=0;y<N;++y) {
        for (int t=0;t<T;++t) {
            double bv = bandwidth_at(uav[x][y], t);
            bval[x][y][t] = bv;
            cap_remain[x][y][t] = bv;
        }
    }

    // Initial solution (greedy)
    solution.assign(FN, {});
    vector<vector<vector<double>>> caps = cap_remain;
    build_initial_solution(solution, caps);

    // SA parameters: initial temperature given by user request (0.3)
    double initial_temp = 0.3;
    double temp = initial_temp;
    double final_temp = 1e-4;
    int max_iters = 4000; // modest number; tune as needed
    double cooling = pow(final_temp / temp, 1.0 / max_iters);

    // seed RNG
    std::mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> flow_pick(0, max(0, FN-1));
    uniform_real_distribution<double> unit01(0.0, 1.0);

    // current solution and score
    double cur_score = compute_weighted_score(solution);
    vector<vector<Assign>> best_solution = solution;
    double best_score = cur_score;

    // SA loop
    for (int iter = 0; iter < max_iters; ++iter) {
        // neighbor: pick random flow and reassign it randomly
        int fidx = flow_pick(rng);
        // make local copy of capacities
        vector<vector<vector<double>>> caps_local = caps;
        // remove fidx assignment (refund)
        refund_flow_caps(fidx, solution, caps_local);
        // randomized reassign
        randomized_assign_flow(fidx, solution, caps_local, rng);
        // compute new score (only flow-level changes affect overall but compute full)
        double new_score = compute_weighted_score(solution);
        double d = new_score - cur_score;
        bool accept = false;
        if (d >= 0) accept = true;
        else {
            double prob = exp(d / max(1e-12, temp));
            if (unit01(rng) < prob) accept = true;
        }
        if (accept) {
            // commit caps_local to caps and update cur_score
            caps.swap(caps_local);
            cur_score = new_score;
            if (new_score > best_score) {
                best_score = new_score;
                best_solution = solution;
            }
        } else {
            // reject: restore solution and do nothing
            // we need to rebuild original solution for fidx from caps (we had refunded it)
            // simpler: restore previous solution by reassigning using deterministic greedy for this flow using current caps
            // But we don't have the old assignments stored; easiest: revert by using best_solution's fidx if available
            // to keep simple and robust: revert full solution to best_solution (safe but slower)
            solution = best_solution;
            // recompute caps from scratch
            caps = cap_remain;
            for (int i=0;i<FN;++i) {
                for (auto &a : solution[i]) {
                    caps[a.x][a.y][a.t] -= a.z;
                    if (caps[a.x][a.y][a.t] < -1e-6) caps[a.x][a.y][a.t] = 0.0; // defensive
                }
            }
            cur_score = best_score;
        }
        // cool
        temp *= cooling;
    }

    // use best_solution for final output
    // Format: for each flow print id p then p lines of t x y z
    // Sort each flow's assigns by time for output clarity
    for (int i=0;i<FN;++i) {
        auto &v = best_solution[i];
        sort(v.begin(), v.end(), [](const Assign &a, const Assign &b){ if (a.t!=b.t) return a.t<b.t; if (a.x!=b.x) return a.x<b.x; return a.y<b.y; });
        cout << flows[i].id << " " << (int)v.size() << "\n";
        cout.setf(std::ios::fixed); cout<<setprecision(6);
        for (auto &a : v) {
            cout << a.t << " " << a.x << " " << a.y << " " << a.z << "\n";
        }
    }

    return 0;
}
