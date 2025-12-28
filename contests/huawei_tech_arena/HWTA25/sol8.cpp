#pragma GCC optimize("Ofast", "unroll-loops", "inline")
#include <bits/stdc++.h>
using namespace std;

static constexpr int PERIOD = 10;
static constexpr double W0 = 40.0;
static constexpr double W1 = 20.0;
static constexpr double W2 = 30.0;
static constexpr double W3 = 10.0;
static constexpr double TAU = 10.0;
static constexpr double BETA = 0.1;
static constexpr double EPS = 1e-9;

static constexpr int CAND_L = 8;
static constexpr int ITER_MAX = 8;
static constexpr double ALPHA_PRICE = 0.6;
static constexpr double SWITCH_MUL = 1.0;

inline int mdist(int ax,int ay,int bx,int by){ return abs(ax-bx) + abs(ay-by); }

inline double bw_at(int phi, double B, int t){
    int u = (phi + t) % PERIOD;
    if (u <= 1 || u >= 8) return 0.0;
    if (u == 2 || u == 7) return B * 0.5;
    return B;
}

struct Flow {
    int id, ax, ay, t0, m1, n1, m2, n2;
    double Q, rem;
    int lastx = -1, lasty = -1;
    int k = 1;
    vector<tuple<int,int,int,double>> sched;
};

struct Cand { int cell, d; double bw; };

int M,N,F,T;
double QT = 0.0;
inline int cidx(int x,int y){ return x*N + y; }

vector<array<double,PERIOD>> BW; // cell -> phase -> capacity
vector<Flow> flows;

vector<vector<double>> pref[PERIOD];

vector<array<vector<Cand>,PERIOD>> CANDS;
vector<array<double,PERIOD>> avgBW;

vector<double> distPow2;

inline double preKey(const Flow& f, int tmod, int x, int y){
    double b = BW[cidx(x,y)][tmod]; if (b <= EPS) return -1e300;
    int d = mdist(f.ax,f.ay,x,y);
    return b * (W0 + W2 * pow(2.0, -BETA * d));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> F >> T;

    const int CELLS = M*N;
    BW.assign(CELLS, array<double,PERIOD>{});

    for (int i=0;i<CELLS;i++){
        int x,y,phi; double B;
        cin >> x >> y >> B >> phi;
        for (int t=0;t<PERIOD;t++) BW[cidx(x,y)][t] = bw_at(phi,B,t);
    }

    for (int t=0;t<PERIOD;t++){
        pref[t].assign(M+1, vector<double>(N+1,0.0));
        for (int x=1;x<=M;x++){
            double row=0.0;
            for (int y=1;y<=N;y++){
                row += BW[cidx(x-1,y-1)][t];
                pref[t][x][y] = pref[t][x-1][y] + row;
            }
        }
    }

    flows.resize(F);
    for (int i=0;i<F;i++){
        int id, ax, ay, t0, m1, n1, m2, n2; double Q;
        cin >> id >> ax >> ay >> t0 >> Q >> m1 >> n1 >> m2 >> n2;
        flows[i] = {id, ax, ay, t0, m1, n1, m2, n2, Q, Q};
        QT += Q;
    }

    distPow2.resize(M+N+5);
    for (int d=0; d<(int)distPow2.size(); ++d) distPow2[d] = pow(2.0, -BETA * d);

    CANDS.assign(F, {});
    avgBW.assign(F, {});
    for (int fid=0; fid<F; ++fid){
        const auto &f = flows[fid];
        for (int t=0; t<PERIOD; ++t){
            struct CK { int x,y; double key; };
            array<CK,CAND_L> top; int used = 0;
            double accBW = 0.0; int cntBW = 0;

            for (int x=f.m1; x<=f.m2; ++x){
                for (int y=f.n1; y<=f.n2; ++y){
                    double b = BW[cidx(x,y)][t];
                    if (b <= EPS) continue;
                    accBW += b; cntBW++;
                    double key = preKey(f,t,x,y);
                    if (used < CAND_L){
                        top[used++] = {x,y,key};
                        int k=used-1; while(k>0 && top[k-1].key < top[k].key){ swap(top[k-1],top[k]); --k; }
                    }else if (key > top[used-1].key){
                        top[used-1] = {x,y,key};
                        int k=used-1; while(k>0 && top[k-1].key < top[k].key){ swap(top[k-1],top[k]); --k; }
                    }
                }
            }
            auto &vec = CANDS[fid][t]; vec.clear(); vec.reserve(used);
            for (int i=0;i<used;i++){
                int x = top[i].x, y = top[i].y;
                vec.push_back({cidx(x,y), mdist(f.ax,f.ay,x,y), BW[cidx(x,y)][t]});
            }
            avgBW[fid][t] = (cntBW ? accBW / cntBW : 0.0);
        }
    }

    vector<int> order(F); iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a,int b){ return flows[a].t0 < flows[b].t0; });
    int nxt = 0;
    vector<int> active; active.reserve(F);

    vector<double> price(CELLS, 0.0), demand(CELLS, 0.0), left(CELLS, 0.0);
    vector<int> touched; touched.reserve(4096);
    vector<int> choice(F, -1);
    vector<int> choiceDist(F, 0);
    vector<double> candVal; candVal.reserve(CAND_L+1);

    for (int t=0; t<T; ++t){
        int tmod = t % PERIOD;

        while (nxt < F && flows[order[nxt]].t0 <= t){
            active.push_back(order[nxt]);
            ++nxt;
        }
        if (active.empty()) continue;

        touched.clear();
        for (int c=0;c<CELLS;c++){
            double b = BW[c][tmod];
            if (b > EPS) { left[c] = b; price[c] = 0.0; demand[c] = 0.0; touched.push_back(c); }
        }

        for (int it=0; it<ITER_MAX; ++it){
            for (int c : touched) demand[c] = 0.0;

            const double delayTerm = W1 * (TAU / (t + TAU));
            for (int fid : active){
                auto &f = flows[fid];
                if (f.rem <= EPS) { choice[fid] = -1; continue; }

                double sw_per_unit = 0.0;
                if (f.lastx != -1) {
                    int kold = f.k;
                    double d1k = (1.0/(kold+1) - 1.0/kold);
                    double zhat = max(1e-9, min(f.rem, avgBW[fid][tmod]));
                    sw_per_unit = SWITCH_MUL * (- W3 * (f.Q / (QT + 1e-12)) * d1k) / zhat;
                }

                int bestC = -1, bestD = 0;
                double bestU = -1e300;

                auto eval = [&](int c, int d, bool isSwitch){
                    double bcap = BW[c][tmod]; if (bcap <= EPS) return;
                    double v = W0 + delayTerm + W2 * distPow2[d];
                    double u = v - price[c] - (isSwitch ? sw_per_unit : 0.0);
                    if (u > bestU) { bestU = u; bestC = c; bestD = d; }
                };

                if (f.lastx != -1){
                    int cx = f.lastx, cy = f.lasty;
                    if (f.m1 <= cx && cx <= f.m2 && f.n1 <= cy && cy <= f.n2){
                        int c = cidx(cx,cy);
                        eval(c, mdist(f.ax,f.ay,cx,cy), false);
                    }
                }

                for (const auto &cand : CANDS[fid][tmod]){
                    bool isSwitch = !(f.lastx == cand.cell / N && f.lasty == cand.cell % N);
                    eval(cand.cell, cand.d, isSwitch);
                }

                if (bestC == -1) { choice[fid] = -1; continue; }
                choice[fid] = bestC; choiceDist[fid] = bestD;

                double want = min(f.rem, BW[bestC][tmod]);
                demand[bestC] += want;
            }

            bool smallGap = true;
            for (int c : touched){
                double cap = left[c];
                if (cap <= EPS) continue;
                double gap = (demand[c] - cap) / (cap + 1e-9);
                if (fabs(gap) > 0.05) smallGap = false;
                price[c] += ALPHA_PRICE * gap;
            }
            if (smallGap) break;
        }

        vector<vector<pair<int,int>>> chooser(CELLS);
        chooser.reserve(1024);
        int usedCells = 0;
        for (int fid : active){
            if (choice[fid] == -1 || flows[fid].rem <= EPS) continue;
            chooser[choice[fid]].push_back({fid, choiceDist[fid]});
        }

        for (int c : touched){
            double cap = left[c];
            if (cap <= EPS) continue;
            auto &vec = chooser[c];
            if (vec.empty()) continue;

            int DMAX = (int)distPow2.size()-1;
            static vector<int> usedD, cnt, pos; usedD.clear();
            cnt.assign(DMAX+1, 0);

            for (auto &p : vec){
                int d = p.second; cnt[d]++; if (cnt[d]==1) usedD.push_back(d);
            }
            sort(usedD.begin(), usedD.end());
            pos.assign(DMAX+1, 0);
            int acc = 0; for (int d : usedD){ int k = cnt[d]; pos[d] = acc + k; acc += k; }

            vector<pair<int,int>> ordered(vec.size());
            for (auto &p : vec){
                int d = p.second;
                ordered[--pos[d]] = p; // stable not required
            }

            for (auto &p : ordered){
                if (cap <= EPS) break;
                int fid = p.first;
                Flow &f = flows[fid];
                if (f.rem <= EPS) continue;
                double z = min(f.rem, cap);
                if (z <= EPS) continue;

                int x = c / N, y = c % N;
                f.sched.emplace_back(t, x, y, z);
                f.rem -= z; cap -= z;

                if (!(f.lastx == x && f.lasty == y)){
                    if (f.lastx != -1) f.k += 1;
                    f.lastx = x; f.lasty = y;
                }
            }
            left[c] = cap;
        }

    }

    cout.setf(std::ios::fixed); cout << setprecision(7);
    for (const auto &f : flows){
        cout << f.id << " " << (int)f.sched.size() << "\n";
        for (auto &r : f.sched) {
            int t,x,y; double z; tie(t,x,y,z) = r;
            cout << t << " " << x << " " << y << " " << z << "\n";
        }
    }
    return 0;
}
