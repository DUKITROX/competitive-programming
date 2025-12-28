#pragma GCC optimize("Ofast","unroll-loops","inline")
#include <bits/stdc++.h>
using namespace std;

// ------------------ Problem constants (from statement) -----------------------
static constexpr int PERIOD = 10;
static constexpr double W0 = 0.4, W1 = 0.2, W2 = 0.3, W3 = 0.1;
static constexpr double TAU = 10.0, BETA = 0.1;
static constexpr double EPS  = 1e-9;

// ------------------ Heuristic knobs (safe defaults) --------------------------
static constexpr int    HORIZON       = 30;     // look-ahead seconds
static constexpr int    CAND_L        = 100;     // top-L candidates per flow & phase
static constexpr double LAMBDA_CONG   = 0.20;  // congestion sensitivity
static constexpr double GAMMA_DECAY   = 0.85;  // look-ahead discount per step
static constexpr double TEMP          = 0.10;  // softmax temperature (as requested)

// ------------------ Small RNG & utils ---------------------------------------
struct XorShift64 {
    uint64_t s; explicit XorShift64(uint64_t seed=0x9e3779b97f4a7c15ULL): s(seed){}
    inline uint64_t next() { s ^= s << 7; s ^= s >> 9; return s; }
    inline double uniform(){ return ((next() >> 11) + 0.5) / (double)(~0ULL >> 11); } // (0,1)
};
inline int mdist(int ax,int ay,int bx,int by){ return abs(ax-bx) + abs(ay-by); }
inline double bw_at(int phi,double B,int t){
    int u = (phi + t) % PERIOD;
    if (u <= 1 || u >= 8) return 0.0;
    if (u == 2 || u == 7) return B * 0.5;
    return B;
}

// ------------------ Fenwick for weighted sampling ----------------------------
struct Fenwick {
    int n=0; vector<double> bit;
    void build(const vector<double>& a){ n=(int)a.size(); bit.assign(n+1,0.0);
        for(int i=1;i<=n;i++){ bit[i]+=a[i-1]; int j=i+(i&-i); if(j<=n) bit[j]+=bit[i]; } }
    inline double total() const { double s=0; for(int i=n;i>0;i-=i&-i) s+=bit[i]; return s; }
    inline double point(int i) const {
        double s=bit[i+1]; int z=(i+1)-((i+1)&-(i+1));
        for (int x=i; x!=z; x-=x&-x) s-=bit[x];
        return s;
    }
    inline void add(int i,double v){ for(int x=i+1;x<=n;x+=x&-x) bit[x]+=v; }
    inline void setZero(int i){ double cur=point(i); if (cur!=0.0) add(i,-cur); }
    // return smallest idx with prefix >= target (target in (0,total])
    int lower_bound(double target) const {
        int idx=0; double acc=0.0;
        int pw=1; while((pw<<1)<=n) pw<<=1;
        for(int step=pw; step; step>>=1){
            int nxt=idx+step;
            if (nxt<=n && acc+bit[nxt] < target) { acc+=bit[nxt]; idx=nxt; }
        }
        return idx; // 0-based
    }
};

// ------------------ Problem data ---------------------------------------------
struct Flow {
    int id, ax, ay, t0, m1, n1, m2, n2;
    double Q, rem;
    int lastx=-1, lasty=-1; // previous landing
    int k=1;                // k starts at 1 (brief)
    vector<tuple<int,int,int,double>> sched; // (t,x,y,z)
};
struct Cand { int cell, d; double bw; };

int M,N,F,T;
double SUM_Q=0.0;
inline int cidx(int x,int y){ return x*N + y; }

vector<array<double,PERIOD>> BW;               // cell -> phase -> BW
vector<Flow> flows;
vector<array<vector<Cand>,PERIOD>> CANDS;      // top-L per flow & phase
vector<array<double,PERIOD>> avgBW;            // avg candidate BW per flow & phase
vector<double> distPow2;

// quick rank key used for preselect
inline double preKey(const Flow& f,int tmod,int x,int y){
    double b = BW[cidx(x,y)][tmod]; if (b<=EPS) return -1e100;
    int d = mdist(f.ax,f.ay,x,y);
    return b * (W0 + W2 * pow(2.0, -BETA * d));
}

// ------------------ Main ------------------------------------------------------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> F >> T;
    const int CELLS = M*N;

    // UAVs
    BW.assign(CELLS, array<double,PERIOD>{});
    for (int i=0;i<CELLS;i++){
        int x,y,phi; double B;
        cin >> x >> y >> B >> phi;
        for (int t=0;t<PERIOD;t++) BW[cidx(x,y)][t] = bw_at(phi,B,t);
    }

    // Flows
    flows.resize(F);
    for (int i=0;i<F;i++){
        int id,ax,ay,t0,m1,n1,m2,n2; double Q;
        cin >> id >> ax >> ay >> t0 >> Q >> m1 >> n1 >> m2 >> n2;
        flows[i] = {id,ax,ay,t0,m1,n1,m2,n2,Q,Q};
        SUM_Q += Q;
    }

    // Precompute distance powers
    distPow2.resize(M+N+5);
    for (int d=0; d<(int)distPow2.size(); ++d) distPow2[d] = pow(2.0, -BETA*d);

    // Precompute top-L candidates and avg BW per flow & phase
    CANDS.assign(F, {});
    avgBW.assign(F, {});
    for (int fid=0; fid<F; ++fid){
        const auto &f = flows[fid];
        for (int t=0; t<PERIOD; ++t){
            struct CK{ int x,y; double key; };
            array<CK,CAND_L> top; int used=0;
            double acc=0.0; int cnt=0;

            for (int x=f.m1; x<=f.m2; ++x){
                for (int y=f.n1; y<=f.n2; ++y){
                    double b = BW[cidx(x,y)][t];
                    if (b<=EPS) continue;
                    acc += b; cnt++;
                    double key = preKey(f,t,x,y);
                    if (used < CAND_L){
                        top[used++] = {x,y,key};
                        int k=used-1; while(k>0 && top[k-1].key < top[k].key){ swap(top[k-1],top[k]); --k; }
                    } else if (key > top[used-1].key){
                        top[used-1] = {x,y,key};
                        int k=used-1; while(k>0 && top[k-1].key < top[k].key){ swap(top[k-1],top[k]); --k; }
                    }
                }
            }
            auto &vec = CANDS[fid][t]; vec.clear(); vec.reserve(used);
            for (int i=0;i<used;i++){
                int x=top[i].x, y=top[i].y, c=cidx(x,y);
                vec.push_back({c, mdist(f.ax,f.ay,x,y), BW[c][t]});
            }
            avgBW[fid][t] = (cnt? acc/cnt : 0.0);
        }
    }

    // Activate flows by start time
    vector<int> order(F); iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a,int b){ return flows[a].t0 < flows[b].t0; });
    int nxt=0; vector<int> active; active.reserve(F);

    // Reusable buffers
    vector<double> left(CELLS,0.0), predDem(CELLS,0.0);
    vector<int> touched; touched.reserve(4096);

    // Global softmax request list per second
    struct Req { int fid, cell, d; double w; };
    vector<Req> req; req.reserve(60000);
    vector<double> w;  w.reserve(60000);
    vector<int> flowL(F,-1), flowR(F,-1);
    vector<vector<int>> cellReq; cellReq.resize(CELLS);

    XorShift64 rng(0xA57C0DE1234567ULL);

    for (int t=0; t<T; ++t){
        int tmod = t % PERIOD;

        // Capacities & touched cells
        touched.clear();
        for (int c=0;c<CELLS;c++){
            double b = BW[c][tmod];
            if (b > EPS){ left[c]=b; touched.push_back(c); }
            else left[c]=0.0;
        }

        // Activate new flows
        while (nxt < F && flows[order[nxt]].t0 <= t){ active.push_back(order[nxt]); ++nxt; }
        if (active.empty()) continue;

        // Predicted demand per cell (phase-wise), using candidate sets (+ stay)
        for (int c : touched) predDem[c]=0.0;
        for (int fid : active){
            auto &f = flows[fid];
            if (f.rem <= EPS) continue;
            double contrib = min(f.rem, avgBW[fid][tmod]);
            // stay
            if (f.lastx!=-1){
                int cx=f.lastx, cy=f.lasty;
                if (f.m1<=cx && cx<=f.m2 && f.n1<=cy && cy<=f.n2){
                    int c = cidx(cx,cy); if (left[c]>EPS) predDem[c] += contrib;
                }
            }
            // candidates
            for (const auto &cd : CANDS[fid][tmod]){
                if (left[cd.cell]>EPS) predDem[cd.cell] += contrib;
            }
        }

        // Build requests with look-ahead value + exact Δ(1/k) (constant if switch)
        req.clear(); w.clear();
        for (int c : touched) cellReq[c].clear();
        std::fill(flowL.begin(), flowL.end(), -1);
        std::fill(flowR.begin(), flowR.end(), -1);

        auto unitVal = [&](double delayTerm, int d){
            return (W0 + delayTerm + W2 * distPow2[d]) / (SUM_Q + 1e-12);
        };

        const double delay0 = W1 * (TAU / (t + TAU));

        for (int fid : active){
            auto &f = flows[fid];
            if (f.rem <= EPS) continue;

            int start = (int)req.size();

            auto addCandidate = [&](int cell, int d, bool isSwitch){
                if (left[cell] <= EPS) return;

                // congestion factor
                double rho = predDem[cell] / (left[cell] + 1e-9);
                double cong = 1.0 / (1.0 + LAMBDA_CONG * max(0.0, rho - 1.0));
                cong = max(0.1, min(1.0, cong)); // clamp a bit

                // look-ahead expected value (including h=0)
                double remSim = f.rem;
                double val = 0.0;
                for (int h=0; h<HORIZON && remSim>EPS; ++h){
                    int ph = (t + h) % PERIOD;
                    double caph = BW[cell][ph];
                    double sendh = min(remSim, caph) * cong;
                    double delayTerm = W1 * (TAU / (t + h + TAU));
                    double dens = unitVal(delayTerm, d);
                    val += pow(GAMMA_DECAY, h) * sendh * dens;
                    remSim -= sendh;
                }

                // exact Δ(1/k) constant if switching
                if (isSwitch && f.lastx != -1){
                    int oldk = max(1, f.k);
                    int newk = oldk + 1;
                    val += W3 * (f.Q / (SUM_Q + 1e-12)) * (1.0/newk - 1.0/oldk);
                }

                // Softmax weight
                double ww = exp( min(20.0, val / TEMP) );
                req.push_back({fid, cell, d, ww});
                w.push_back(ww);
                cellReq[cell].push_back((int)req.size()-1);
            };

            // "stay" if feasible
            if (f.lastx!=-1){
                int cx=f.lastx, cy=f.lasty;
                if (f.m1<=cx && cx<=f.m2 && f.n1<=cy && cy<=f.n2){
                    int c = cidx(cx,cy);
                    addCandidate(c, mdist(f.ax,f.ay,cx,cy), false);
                }
            }
            // top-L candidates
            for (const auto &cd : CANDS[fid][tmod]){
                bool isSwitch = !(f.lastx == cd.cell / N && f.lasty == cd.cell % N);
                addCandidate(cd.cell, cd.d, isSwitch);
            }

            int end = (int)req.size();
            if (start < end){ flowL[fid]=start; flowR[fid]=end; }
        }

        int n = (int)req.size();
        if (n == 0) continue;

        // Softmax sampling with capacity & one-per-flow enforcement
        Fenwick ft; ft.build(w);
        vector<char> taken(F, 0);

        double total = ft.total();
        int remainingToServe = 0;
        for (int fid : active) if (flows[fid].rem > EPS) remainingToServe++;

        while (total > EPS && remainingToServe > 0){
            double r = rng.uniform() * total;
            int rid = ft.lower_bound(r);
            if (rid < 0 || rid >= n) break;

            int fid  = req[rid].fid;
            int cell = req[rid].cell;

            if (taken[fid]){
                ft.setZero(rid);
                total = ft.total();
                continue;
            }

            if (left[cell] <= EPS){
                // zero all requests for this cell
                for (int qid : cellReq[cell]) ft.setZero(qid);
                total = ft.total();
                continue;
            }

            double z = min(left[cell], flows[fid].rem);
            if (z <= EPS){
                // zero this req and possibly the whole flow block
                ft.setZero(rid);
                if (flows[fid].rem <= EPS && flowL[fid] != -1){
                    for (int j=flowL[fid]; j<flowR[fid]; ++j) ft.setZero(j);
                }
                total = ft.total();
                continue;
            }

            // Accept this (flow, cell) for this second
            int x = cell / N, y = cell % N;
            // update k if switching
            if (!(flows[fid].lastx == x && flows[fid].lasty == y)){
                if (flows[fid].lastx != -1) flows[fid].k += 1;
                flows[fid].lastx = x; flows[fid].lasty = y;
            }
            flows[fid].sched.emplace_back(t, x, y, z);
            flows[fid].rem  -= z;
            left[cell]      -= z;

            // enforce one-per-flow this second
            taken[fid] = 1; remainingToServe--;
            if (flowL[fid] != -1){
                for (int j=flowL[fid]; j<flowR[fid]; ++j) ft.setZero(j);
            }
            // if the cell is exhausted, zero all its requests
            if (left[cell] <= EPS){
                for (int qid : cellReq[cell]) ft.setZero(qid);
            }
            total = ft.total();
        }
        // any flow not sampled this second sends nothing (valid).
    }

    // Output in required format
    cout.setf(std::ios::fixed); cout << setprecision(7);
    for (const auto &f : flows){
        cout << f.id << " " << (int)f.sched.size() << "\n";
        for (auto &r : f.sched){
            int tt, xx, yy; double zz;
            tie(tt,xx,yy,zz) = r;
            cout << tt << " " << xx << " " << yy << " " << zz << "\n";
        }
    }
    return 0;
}
