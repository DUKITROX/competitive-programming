#pragma GCC optimize("Ofast", "unroll-loops", "inline")
#include <bits/stdc++.h>
using namespace std;

// intento nuevo de sol desde 0 :(((( AAAAA mi bomboclat

static constexpr double W0 = 0.4, W1 = 0.2, W2 = 0.3, W3 = 0.1, BETA = 0.1, TAU = 10.0, EPS = 1e-9;  
static constexpr int PERIOD = 10;

static constexpr int WINDOW_AHEAD = 40; // intentos de prediccion futura
static constexpr int CAND_PER_PHASE = 8; // uav's mas prometedores por fase, ir tuneandolo tu, puede no funcione

inline int mdist(int ax, int ay, int lx, int ly) { return abs(ax - lx) + abs(ay - ly); }
inline double bw_at(int phi, double B, int t) {int u = (phi + t) % PERIOD;if (u <= 1 || u >= 8) return 0.0;if (u == 2 || u == 7) return B * 0.5;return B;}

struct Rec { int t, x, y; double z; };
struct Flow {
    int id, ax, ay, t0;
    int m1, n1, m2, n2;
    double Q, rem;
    int lastx = -1, lasty = -1;
    int k = 1;                 
    vector<Rec> sched;
    array<double, PERIOD> regionSum10{}; 
    array<vector<int>, PERIOD> cand;     
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, FN, T;
    if (!(cin >> M >> N >> FN >> T)) return 0;
    const int CELLS = M * N;
    vector<array<double, PERIOD>> BW(CELLS);
    auto idx = [N](int x, int y) { return x * N + y; };

    for (int i = 0; i < CELLS; ++i) {
        int x, y, phi; double B;
        cin >> x >> y >> B >> phi;
        for (int t = 0; t < PERIOD; ++t) BW[idx(x,y)][t] = bw_at(phi, B, t);
    }
    const int STRIDE = N + 1;
    vector<vector<double>> pref(PERIOD, vector<double>((M + 1) * (N + 1), 0.0));
    auto pidx = [&](int x1, int y1) { return x1 * STRIDE + y1; }; // 1-indexed helper

    for (int t = 0; t < PERIOD; ++t) {
        // llenar el grid base
        for (int x = 0; x < M; ++x) {
            double row_acc = 0.0;
            for (int y = 0; y < N; ++y) {
                row_acc += BW[idx(x,y)][t];
                pref[t][pidx(x+1, y+1)] = pref[t][pidx(x, y+1)] + row_acc;
            }
        }
    }
    auto rectSum = [&](int tmod, int m1, int n1, int m2, int n2) -> double {
        int x1 = m1, y1 = n1, x2 = m2 + 1, y2 = n2 + 1;
        return pref[tmod][pidx(x2, y2)] - pref[tmod][pidx(x1, y2)] - pref[tmod][pidx(x2, y1)] + pref[tmod][pidx(x1, y1)];
    };

    vector<Flow> flows;
    flows.reserve(FN);
    for (int i = 0; i < FN; ++i) {
        int id, ax, ay, t0, m1, n1, m2, n2; double Q;
        cin >> id >> ax >> ay >> t0 >> Q >> m1 >> n1 >> m2 >> n2;
        flows.push_back({id, ax, ay, t0, m1, n1, m2, n2, Q, Q});
    }

    vector<int> order(FN);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b){ return flows[a].t0 < flows[b].t0; });

    const int DMAX = M + N + 5;
    vector<double> distPow2(DMAX);
    for (int d = 0; d < DMAX; ++d) distPow2[d] = pow(2.0, -BETA * d);

    for (int fi = 0; fi < FN; ++fi) {
        Flow &f = flows[fi];
        for (int t = 0; t < PERIOD; ++t) {
            f.regionSum10[t] = rectSum(t, f.m1, f.n1, f.m2, f.n2);

            struct Cand { int id; double key; };
            array<Cand, CAND_PER_PHASE> top; int used = 0;

            for (int x = f.m1; x <= f.m2; ++x) {
                for (int y = f.n1; y <= f.n2; ++y) {
                    double b = BW[idx(x,y)][t];
                    if (b <= EPS) continue;
                    int d = mdist(f.ax, f.ay, x, y);
                    double key = b * (W0 + W2 * distPow2[d]); 
                    Cand c{ idx(x,y), key };

                    int pos = used;
                    if (used < CAND_PER_PHASE) ++used;
                    else if (top[used-1].key >= c.key) continue;

                    while (pos > 0 && top[pos-1].key < c.key) { 
                        if (pos < used) top[pos] = top[pos-1];
                        --pos;
                    }
                    top[pos] = c;
                }
            }
            f.cand[t].clear();
            f.cand[t].reserve(used);
            for (int i = 0; i < used; ++i) f.cand[t].push_back(top[i].id);
        }
    }

    vector<double> left(CELLS); 
    vector<int> active; active.reserve(FN);
    int nxt = 0; 

    auto windowSupply = [&](const Flow& f, int t)->double {
        int rem = min(WINDOW_AHEAD, T - t);
        if (rem <= 0) return 0.0;
        int full = rem / PERIOD, tail = rem % PERIOD;
        double sum10 = 0.0; for (int u = 0; u < PERIOD; ++u) sum10 += f.regionSum10[u];
        double total = sum10 * full;
        for (int i = 0; i < tail; ++i) total += f.regionSum10[(t + i) % PERIOD];
        return total;
    };

    vector<pair<double,int>> prio; prio.reserve(FN);

    for (int t = 0; t < T; ++t) {
        int tmod = t % PERIOD;
        for (int c = 0; c < CELLS; ++c) left[c] = BW[c][tmod];

        while (nxt < FN && flows[order[nxt]].t0 <= t) {
            active.push_back(order[nxt]);
            ++nxt;
        }

        prio.clear();
        prio.reserve(active.size());
        for (int idxf : active) {
            Flow &f = flows[idxf];
            if (f.rem <= EPS) continue;
            double future = windowSupply(f, t);
            double pressure = f.rem / (future + 1e-9);
            prio.emplace_back(-pressure, idxf);
        }
        if (prio.empty()) continue;
        sort(prio.begin(), prio.end());

        const double delayTerm = W1 * (TAU / (t + TAU));

        auto inRect = [&](const Flow& f, int x, int y){
            return (f.m1 <= x && x <= f.m2 && f.n1 <= y && y <= f.n2);
        };

        for (auto &p : prio) {
            Flow &f = flows[p.second];
            if (f.rem <= EPS) continue;

            int bestCell = -1;
            double bestGain = -1e300;
            double bestSend = 0.0;

            if (f.lastx >= 0 && inRect(f, f.lastx, f.lasty)) {
                int c = idx(f.lastx, f.lasty);
                if (left[c] > EPS) {
                    int d = mdist(f.ax, f.ay, f.lastx, f.lasty);
                    double v_per_unit = (W0 + delayTerm + W2 * distPow2[d]) / f.Q;
                    double z = min(left[c], f.rem);
                    double gain = v_per_unit * z; 
                    if (gain > bestGain) { bestGain = gain; bestCell = c; bestSend = z; }
                }
            }

            const auto &cand = f.cand[tmod];
            for (int c : cand) {
                if (left[c] <= EPS) continue;
                int x = c / N, y = c % N;
                if (x == f.lastx && y == f.lasty) continue;

                int d = mdist(f.ax, f.ay, x, y);
                double v_per_unit = (W0 + delayTerm + W2 * distPow2[d]) / f.Q;
                double z = min(left[c], f.rem);

                double switch_pen = W3 * (1.0 / (f.k + 1) - 1.0 / f.k);

                double gain = v_per_unit * z + switch_pen;
                if (gain > bestGain) { bestGain = gain; bestCell = c; bestSend = z; }
            }

            if (bestCell >= 0 && bestSend > EPS) {
                int x = bestCell / N, y = bestCell % N;
                if (!(x == f.lastx && y == f.lasty)) {
                    f.k += (f.lastx == -1 ? 0 : 1);
                    f.lastx = x; f.lasty = y;
                }
                left[bestCell] -= bestSend;
                f.rem -= bestSend;
                f.sched.push_back({t, x, y, bestSend});
            }
        }
    }

    cout << fixed << setprecision(7);
    for (const auto &f : flows) {
        cout << f.id << " " << (int)f.sched.size() << "\n";
        for (const auto &r : f.sched) cout << r.t << " " << r.x << " " << r.y << " " << r.z << "\n";
    }
    return 0;
}