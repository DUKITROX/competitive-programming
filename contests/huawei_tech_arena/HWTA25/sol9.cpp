#pragma GCC optimize("Ofast", "unroll-loops", "inline")
#include <bits/stdc++.h>
using namespace std;

// ====================== Problem & scoring constants ==========================
static constexpr int PERIOD = 10;
static constexpr double W0 = 40.0; // 0.4 * 100
static constexpr double W1 = 20.0; // 0.2 * 100
static constexpr double W2 = 30.0; // 0.3 * 100
static constexpr double W3 = 10.0; // 0.1 * 100
static constexpr double TAU = 10.0;  // delay smoothing
static constexpr double BETA = 0.1;  // distance exponent
static constexpr double EPS = 1e-9;

// ============================== Tunables =====================================
static constexpr int K_STATES   = 3;   // beam width
static constexpr int H_CHILDREN = 3;   // children per state per second
static constexpr int MIN_TRF    = 10;   // top candidates per flow per phase (preselect)
static constexpr double TEMP    = 0.2; // softmax temperature

// ============================== RNG / utils ==================================
static inline uint64_t splitmix64(uint64_t &x) {
    uint64_t z = (x += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}
struct FastRNG {
    uint64_t state;
    explicit FastRNG(uint64_t seed=0x1234567890abcdefULL): state(seed) {}
    inline double uniform() {
        // (0,1)
        const double ONE = 1.0 / (double)(~0ULL >> 11);
        return ((splitmix64(state) >> 11) + 0.5) * ONE;
    }
};

// Manhattan distance
inline int mdist(int ax, int ay, int lx, int ly){ return abs(ax - lx) + abs(ay - ly); }

// Periodic BW
inline double getBW(int phi, double B, int t){
    int u = (phi + t) % PERIOD;
    if (u <= 1 || u >= 8) return 0.0;
    if (u == 2 || u == 7) return B * 0.5;
    return B;
}

// ============================== Structures ===================================
struct Rec { int fid; int t, x, y; double z; }; // fid is 0..F-1

struct FlowMeta{
    int id, ax, ay, t0, m1, n1, m2, n2;
    double Q;
};

struct LogNode {
    shared_ptr<LogNode> prev;
    vector<Rec> ops; // ops for one time slot (t)
    LogNode() {}
    LogNode(shared_ptr<LogNode> p, vector<Rec>&& v) : prev(move(p)), ops(move(v)) {}
};

struct State {
    int t = 0;
    double score = 0.0;
    vector<double> rem; // remaining amount per flow
    vector<int> lx, ly; // last landing
    vector<int> k;      // number of landing points so far (starts at 0 here)
    shared_ptr<LogNode> log; // persistent per-second ops chain
    State(){}
    State(int F): rem(F), lx(F,-1), ly(F,-1), k(F,0) {}
};

// Treq candidate (preselected)
struct Treq {
    int fid, x, y; // flow & landing cell
};

// Lightweight candidate at runtime
struct Cand {
    int fid, ridx, cell; // flow id, index in req vector, cell idx
};

// Fenwick tree for weighted sampling
struct Fenwick {
    int n = 0;
    vector<double> bit;
    inline void init(int n_) { n = n_; bit.assign(n+1, 0.0); }
    inline void build(const vector<double>& a) { // O(n)
        n = (int)a.size();
        bit.assign(n+1, 0.0);
        for (int i = 1; i <= n; ++i) {
            bit[i] += a[i-1];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }
    inline void add(int i, double v){ for (int x = i+1; x <= n; x += x & -x) bit[x] += v; }
    inline double sumPrefix(int i) const { double s = 0.0; for (int x = i; x > 0; x -= x & -x) s += bit[x]; return s; }
    inline double total() const { return sumPrefix(n); }
    inline double point(int i) const {
        double s = bit[i+1];
        int z = (i+1) - ((i+1) & -(i+1));
        for (int x = i; x != z; x -= x & -x) s -= bit[x];
        return s;
    }
    inline void setZero(int i){
        double cur = point(i);
        if (cur != 0.0) add(i, -cur);
    }
    // find smallest idx with prefix sum >= target (target in (0,total])
    inline int lower_bound(double target) const {
        int idx = 0;
        double acc = 0.0;
        int pw = 1; while ((pw<<1) <= n) pw <<= 1;
        for (int step = pw; step; step >>= 1) {
            int next = idx + step;
            if (next <= n && acc + bit[next] < target) {
                acc += bit[next];
                idx = next;
            }
        }
        return idx; // 0-based index
    }
};

// ============================== Globals ======================================
int M,N,F,T;
double QT = 0.0; // sum of Q
vector<array<double,10>> BW; // [cell][phase]
vector<vector<double>> pref[10]; // per-phase prefix (1-indexed)
inline int cidx(int x,int y){ return x*N + y; }

vector<FlowMeta> fm;                  // flow meta
vector<array<vector<Treq>,10>> avTreq;// preselected candidates per flow per phase

// 2D prefix sum query for rectangle (inclusive)
inline double rectSum(int tmod, int m1, int n1, int m2, int n2){
    auto &P = pref[tmod];
    int X1 = m1, Y1 = n1, X2 = m2+1, Y2 = n2+1; // 1-indexed in P
    return P[X2][Y2] - P[X1][Y2] - P[X2][Y1] + P[X1][Y1];
}

// preselect ranking used during avTreq build (coarse heuristic, like yours)
inline double preKey(const FlowMeta& f, int tmod, int x, int y){
    double b = BW[cidx(x,y)][tmod];
    if (b <= EPS) return -1e100;
    int d = mdist(f.ax,f.ay,x,y);
    double s1 = 20.0 * pow(2.0, -BETA * d);
    double s2 = 20.0 * (f.Q / (rectSum(tmod, f.m1, f.n1, f.m2, f.n2) + 1e-9));
    double s3 = 60.0 * b;
    return (s1 + s2 + s3);
}

// runtime softmax weight (uses current k & remaining q)
inline double softWeight(const State& s, const FlowMeta& f, int fid, int t, int x, int y, double rem){
    int d = mdist(f.ax,f.ay,x,y);
    int kNew = s.k[fid] + ((s.lx[fid] == x && s.ly[fid] == y) ? 0 : 1);
    double s1 = (W0 * rem) / (f.Q + 1e-12);
    double s2 = (W1 * rem) / (f.Q + 1e-12) * (TAU / (t + TAU));
    double s3 = (W2 * rem) / (f.Q + 1e-12) * pow(2.0, -BETA * d);
    double s4 = (W3) * (1.0 / (double)max(1,kNew)); // heuristic term inside selection
    double sTot = s1 + s2 + s3 + s4;
    return exp(sTot / TEMP);
}

// ================================ Main =======================================
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> F >> T;

    // Read UAVs and fill BW (per phase)
    const int CELLS = M*N;
    BW.assign(CELLS, array<double,10>{});
    for(int i=0;i<CELLS;i++){
        int x,y,phi; double B;
        cin >> x >> y >> B >> phi;
        for(int t=0;t<10;t++) BW[cidx(x,y)][t] = getBW(phi,B,t);
    }

    // Build per-phase 2D prefix sums (1-indexed)
    for(int t=0;t<10;t++){
        pref[t].assign(M+1, vector<double>(N+1,0.0));
        for(int x=1;x<=M;x++){
            double acc=0.0;
            for(int y=1;y<=N;y++){
                acc += BW[cidx(x-1,y-1)][t];
                pref[t][x][y] = pref[t][x-1][y] + acc;
            }
        }
    }

    // Read flows
    fm.resize(F);
    for(int i=0;i<F;i++){
        int id, ax, ay, t0, m1, n1, m2, n2; double Q;
        cin >> id >> ax >> ay >> t0 >> Q >> m1 >> n1 >> m2 >> n2;
        fm[i] = {id, ax, ay, t0, m1, n1, m2, n2, Q};
        QT += Q;
    }

    // Sort flow indices by start time to activate quickly
    vector<int> order(F); iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a,int b){ return fm[a].t0 < fm[b].t0; });

    // Precompute per-flow top MIN_TRF candidates for each phase (like your avTreq)
    avTreq.resize(F);
    for(int fid=0; fid<F; ++fid){
        const auto &fl = fm[fid];
        for(int t=0; t<10; ++t){
            struct CellKey { int x,y; double key; };
            // maintain small top-MIN_TRF array
            array<CellKey, MIN_TRF> top; int used=0;
            for(int x=fl.m1; x<=fl.m2; ++x){
                for(int y=fl.n1; y<=fl.n2; ++y){
                    double b = BW[cidx(x,y)][t];
                    if (b <= EPS) continue;
                    double key = preKey(fl, t, x, y);
                    if (used < MIN_TRF){
                        top[used++] = {x,y,key};
                        int j=used-1; while(j>0 && top[j-1].key < top[j].key){ swap(top[j-1], top[j]); --j; }
                    }else if (key > top[used-1].key){
                        top[used-1] = {x,y,key};
                        int j=used-1; while(j>0 && top[j-1].key < top[j].key){ swap(top[j-1], top[j]); --j; }
                    }
                }
            }
            avTreq[fid][t].clear();
            for(int i=0;i<used;i++) avTreq[fid][t].push_back({fid, top[i].x, top[i].y});
        }
    }

    // Initialize beam with a single state
    vector<State> beam;
    beam.reserve(K_STATES);
    beam.emplace_back(F);
    beam[0].t = 0;
    beam[0].score = 0.0;
    // rem already zero; set to Q
    for(int i=0;i<F;i++) beam[0].rem[i] = fm[i].Q;

    // Global activation tracker (shared by all states since t is the same)
    int nxt = 0;
    vector<int> active; active.reserve(F);

    FastRNG rng(0x3141592653589793ULL);

    // ---------- Main timeline ----------
    for(int t=0; t<T; ++t){
        int tmod = t % 10;

        // Activate new flows
        while(nxt < F && fm[order[nxt]].t0 <= t){
            active.push_back(order[nxt]);
            ++nxt;
        }
        if (active.empty()) { for (auto &s: beam) s.t = t+1; continue; }

        struct Child {
            int parent;
            double deltaScore;
            vector<Rec> ops; // ops for this second
        };
        vector<Child> children; children.reserve((int)beam.size() * H_CHILDREN);

        // Precompute per-second cell capacity
        vector<double> baseLeft(CELLS);
        for(int c=0;c<CELLS;c++) baseLeft[c] = BW[c][tmod];

        // Expand each parent state
        for (int si=0; si<(int)beam.size(); ++si){
            State &S = beam[si];

            // Build req list once (for this parent), with weights
            // Layout: [all flow fid in active with rem>0] each contributes ≤ MIN_TRF entries (contiguous)
            vector<Treq> req; req.reserve(active.size() * MIN_TRF);
            vector<int> start(F, -1), end(F, -1);
            vector<double> w; w.reserve(active.size() * MIN_TRF);

            for (int fid : active){
                if (S.rem[fid] <= EPS) continue;
                const auto &lst = avTreq[fid][tmod];
                if (lst.empty()) continue;
                start[fid] = (int)req.size();
                for (const auto& tr : lst){
                    req.push_back(tr);
                    double sw = softWeight(S, fm[fid], fid, t, tr.x, tr.y, S.rem[fid]); // like your processTreq
                    w.push_back(sw);
                }
                end[fid] = (int)req.size();
            }
            int n = (int)req.size();
            if (n == 0){
                // nothing to schedule from this parent; still create H children with zero delta
                for (int h=0; h<H_CHILDREN; ++h) children.push_back({si, 0.0, {}});
                continue;
            }

            // Build per-cell index lists to bulk zero when capacity exhausts
            vector<vector<int>> cellReq(n ? CELLS : 0);
            vector<int> rid2cell(n);
            for (int i=0;i<n;i++){
                int c = cidx(req[i].x, req[i].y);
                rid2cell[i] = c;
                cellReq[c].push_back(i);
            }

            // For each child, sample with a Fenwick tree over the same weights; use fresh left[]
            for (int h=0; h<H_CHILDREN; ++h){
                vector<double> left = baseLeft; // local capacity copy
                Fenwick ft; ft.build(w);

                vector<char> processed(F, 0);
                double step = 0.0;
                vector<Rec> ops; ops.reserve(256);

                double totalW = ft.total();
                while (totalW > EPS){
                    double pick = rng.uniform() * totalW;
                    int rid = ft.lower_bound(pick);
                    if (rid < 0 || rid >= n) break;

                    int fid = req[rid].fid;
                    if (processed[fid]){
                        ft.setZero(rid);
                        totalW = ft.total();
                        continue;
                    }

                    int c = rid2cell[rid];
                    double z = min(S.rem[fid], left[c]);
                    if (z <= EPS){
                        // reject; if cell is fully exhausted, zero all rids for this cell
                        ft.setZero(rid);
                        if (left[c] <= EPS){
                            for (int qid : cellReq[c]) ft.setZero(qid);
                        }
                        totalW = ft.total();
                        continue;
                    }

                    // Accept this Treq for the flow fid (only once per second)
                    processed[fid] = 1;

                    // Remove all requests for this flow from the pool
                    for (int j = start[fid]; j < end[fid]; ++j) ft.setZero(j);
                    totalW = ft.total();

                    // Update capacities
                    left[c] -= z;

                    // Score delta (exact, like your updateS)
                    int d = mdist(fm[fid].ax, fm[fid].ay, req[rid].x, req[rid].y);
                    int oldk = max(1, S.k[fid]); // per statement starts at 1; we store 0->treated as 1 here
                    bool switched = !(S.lx[fid] == req[rid].x && S.ly[fid] == req[rid].y);
                    int newk = oldk + (S.lx[fid] == -1 ? 0 : (switched ? 1 : 0)); // first booking doesn't increase

                    step += (W0 * z / (QT + 1e-12));
                    step += (W1 * z / (QT + 1e-12)) * (TAU / (t + TAU));
                    step += (W2 * z / (QT + 1e-12)) * pow(2.0, -BETA * d);
                    step += (W3 * fm[fid].Q / (QT + 1e-12)) * (1.0 / (double)newk - 1.0 / (double)oldk);

                    ops.push_back({fid, t, req[rid].x, req[rid].y, z});
                } // while sampling

                children.push_back({si, step, move(ops)});
            } // children
        } // parents

        // Select top K children globally
        struct Pick { int parent; double tot; vector<Rec> *ops; };
        vector<Pick> picks; picks.reserve(children.size());
        for (auto &ch : children){
            double tot = beam[ch.parent].score + ch.deltaScore;
            picks.push_back({ch.parent, tot, &ch.ops});
        }
        nth_element(picks.begin(), picks.begin()+min((int)picks.size(), K_STATES)-1, picks.end(),
            [](const Pick& a, const Pick& b){ return a.tot > b.tot; });
        sort(picks.begin(), picks.begin()+min((int)picks.size(), K_STATES),
            [](const Pick& a, const Pick& b){ return a.tot > b.tot; });

        int keep = min((int)picks.size(), K_STATES);
        vector<State> next; next.reserve(keep);

        for (int i=0;i<keep;i++){
            const auto &pk = picks[i];
            const State &P = beam[pk.parent];
            State S(F);
            S.t = t+1;
            S.score = pk.tot;
            // copy arrays once (K times only)
            S.rem = P.rem; S.lx = P.lx; S.ly = P.ly; S.k = P.k;

            // apply ops
            auto &ops = *pk.ops;
            for (const auto &op : ops){
                int fid = op.fid;
                S.rem[fid] -= op.z;
                if (!(S.lx[fid] == op.x && S.ly[fid] == op.y)){
                    if (S.lx[fid] != -1) S.k[fid] += 1;
                    S.lx[fid] = op.x; S.ly[fid] = op.y;
                }
            }
            S.log = make_shared<LogNode>(P.log, vector<Rec>(ops.begin(), ops.end()));
            next.emplace_back(move(S));
        }

        beam.swap(next);
        if (beam.empty()){
            // no survivors, keep one empty state to proceed
            beam.emplace_back(F);
            beam[0].t = t+1;
        }
    }

    // Pick best final state
    int best = 0;
    for (int i=1;i<(int)beam.size();++i) if (beam[i].score > beam[best].score) best = i;

    // Reconstruct schedule by flows
    vector<vector<Rec>> perFlow(F);
    vector<shared_ptr<LogNode>> chain;
    for (auto p = beam[best].log; p; p = p->prev) chain.push_back(p);
    // chain holds nodes from last->...->root; output in forward time
    for (int i=(int)chain.size()-1; i>=0; --i){
        for (const auto &op : chain[i]->ops) if (op.z > EPS) {
            perFlow[op.fid].push_back(op);
        }
    }

    // Output in required format
    cout.setf(std::ios::fixed); cout<<setprecision(7);
    for (int fid=0; fid<F; ++fid){
        cout << fm[fid].id << " " << (int)perFlow[fid].size() << "\n";
        for (auto &r : perFlow[fid]){
            cout << r.t << " " << r.x << " " << r.y << " " << r.z << "\n";
        }
    }
    return 0;
}
