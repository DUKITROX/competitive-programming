/*
This solution attempts beam search and we select each Treq iterativly 
*/

#include <bits/stdc++.h>
using namespace std;

#define double long double

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef double TT; // long double, Rational, double + mod<P>...
typedef vector<TT> vd;
typedef vector<vd> vvd;

const TT eps = 1e-8, inf = 1/.0;
#define MP make_pair
#define ltj(X) if(s == -1 || MP(X[j],N[j]) < MP(X[s],N[s])) s=j

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 
#define urd(a,b) uniform_real_distribution<double>(a, b)(rng)

inline int mdist(int ax, int ay, int lx, int ly){return abs(ax-lx) + abs(ay-ly);}
inline double getBW(int phi, double B, int t){t += phi; t %= 10;if (t <= 1 || t >= 8) return 0.0L;else if (t == 2 || t == 7) return B / 2.0L;else return B;}

struct LPSolver {
	int m, n;
	vi N, B;
	vvd D;

	LPSolver(const vvd& A, const vd& b, const vd& c) :
		m(sz(b)), n(sz(c)), N(n+1), B(m), D(m+2, vd(n+2)) {
			rep(i,0,m) rep(j,0,n) D[i][j] = A[i][j];
			rep(i,0,m) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i];}
			rep(j,0,n) { N[j] = j; D[m][j] = -c[j]; }
			N[n] = -1; D[m+1][n] = 1;
		}

	void pivot(int r, int s) {
		TT *a = D[r].data(), inv = 1 / a[s];
		rep(i,0,m+2) if (i != r && abs(D[i][s]) > eps) {
			TT *b = D[i].data(), inv2 = b[s] * inv;
			rep(j,0,n+2) b[j] -= a[j] * inv2;
			b[s] = a[s] * inv2;
		}
		rep(j,0,n+2) if (j != s) D[r][j] *= inv;
		rep(i,0,m+2) if (i != r) D[i][s] *= -inv;
		D[r][s] = inv;
		swap(B[r], N[s]);
	}

	bool simplex(int phase) {
		int x = m + phase - 1;
		for (;;) {
			int s = -1;
			rep(j,0,n+1) if (N[j] != -phase) ltj(D[x]);
			if (D[x][s] >= -eps) return true;
			int r = -1;
			rep(i,0,m) {
				if (D[i][s] <= eps) continue;
				if (r == -1 || MP(D[i][n+1] / D[i][s], B[i])
				             < MP(D[r][n+1] / D[r][s], B[r])) r = i;
			}
			if (r == -1) return false;
			pivot(r, s);
		}
	}

	TT solve(vd &x) {
		int r = 0;
		rep(i,1,m) if (D[i][n+1] < D[r][n+1]) r = i;
		if (D[r][n+1] < -eps) {
			pivot(r, n);
			if (!simplex(2) || D[m+1][n+1] < -eps) return -inf;
			rep(i,0,m) if (B[i] == -1) {
				int s = 0;
				rep(j,1,n+1) ltj(D[i]);
				pivot(i, s);
			}
		}
		bool ok = simplex(1); x = vd(n);
		rep(i,0,m) if (B[i] < n) x[B[i]] = D[i][n+1];
		return ok ? D[m][n+1] : inf;
	}
};


struct Flow{
	int id,m1,n1,m2,n2;
	int ax,ay,lx,ly;
	int t0,k;
	double Q,q;
	vector<tuple<int,int,int,double>> sched;
	bool operator<(const Flow& other) const{return t0 < other.t0;}
};
ostream& operator<<(ostream& os, const Flow& flow){
	os << flow.id << " " << (int)flow.sched.size() << "\n";
	for(const auto &e : flow.sched) os << (get<0>(e)) << " " << get<1>(e) << " " << get<2>(e) << " " << get<3>(e) << "\n";
	return os;
}
struct State{
	int t,it; double score;
	vector<Flow> flows; // all flows
	set<int> actf; // active flows
	
	State() : t(0), score(10.0L), it(0){}
	State(const State& s){
		t = s.t; 
		score = s.score;
		flows = s.flows;
		actf = s.actf;
		it = s.it;
	}
	bool operator<(const State& other)const{return score > other.score;}
};
struct Treq{
	int fid,lx,ly;
	int d,k;
	double score,q;
	
	Treq(int fid, int lx, int ly, double q) : fid(fid), lx(lx), ly(ly), q(q){}
	bool operator<(const Treq& other) const {return score > other.score || score == other.score && fid > other.fid;}
};

constexpr int K = 10, H = 10, MAX_ITER = 3; // states per timeslot & children per state
constexpr double EPS = 1e-9;
int M,N,F,T; double QT=0.0L;
vector<vector<vector<double>>> BW;

// updates State with Treq
void updateS(State& s, Treq& tr, double q){
	s.flows[tr.fid].sched.emplace_back(tuple<int,int,int,double>{s.t, tr.lx, tr.ly, q});
	if ((s.flows[tr.fid].q -= q) < EPS)
		s.actf.erase(tr.fid);

	s.score += 40.0L*q/QT;
	s.score += 20.0L*q/QT*10/(10+s.t);
	s.score += 30.0L*q/QT*pow(2,-0.1*tr.d);
	s.score += 10.0L*s.flows[tr.fid].Q/QT * (1.0L/tr.k - 1.0L/max(1, s.flows[tr.fid].k));

	s.flows[tr.fid].k = tr.k;
	s.flows[tr.fid].lx = tr.lx;
	s.flows[tr.fid].ly = tr.ly;
}

// IMP : evaluates Treq 
void processTreq(State& s, Treq& tr){
	int d = tr.d = mdist(s.flows[tr.fid].ax, s.flows[tr.fid].ay, tr.lx, tr.ly);
	int k = tr.k = s.flows[tr.fid].k + !(s.flows[tr.fid].lx == tr.lx && s.flows[tr.fid].ly == tr.ly);

	double s1 = 40.0L * tr.q / s.flows[tr.fid].Q;
	double s2 = 20.0L * tr.q / s.flows[tr.fid].Q * 10.0L / (s.t + 10.0L);
	double s3 = 30.0L * tr.q / s.flows[tr.fid].Q * pow(2.0L, -0.1*d);
	double s4 = 10.0L / k;

	tr.score += s1 + s2 + s3 + s4;
}

// IMP : processes State
void processState(State& s, deque<State>& dq){
    while(s.it < F && s.flows[s.it].t0 <= s.t) s.actf.insert(s.it++);
	vector<vector<double>> bw(M,vector<double>(N,0.0L));
	vector<vector<double>> 

	for(const int& i : s.actf)
		for(int lx = s.flows[i].m1; lx <= s.flows[i].m2; lx++)
			for(int ly = s.flows[i].n1; ly <= s.flows[i].n2; ly++){
                Treq tr{i,lx,ly,s.flows[i].q};
				processTreq(s, tr);
                req.insert(tr);
			}
    
    // process "hijos"
    for(int h = 0; h < H; h++){
        State sh(s);        
        
        for(int _=0; _<MAX_ITER && !req.empty();_++){

            auto it = req.begin();
            int cont = 0;
            while(it != req.end()){
                const Treq &tr = *it;

                int lx = tr.lx, ly = tr.ly;
                double q = min(tr.q, max(0.0L, BW[lx][ly][(s.t%10)] - bw[lx][ly]));

                if(q > EPS){

                }else{

                }
            }
        }
		while(st.query(0, n) > EPS){
			int rid = st.lower_bound(urd(0.0L, st.query(0,n))); 
			int fid = req[rid].fid;
			if(rid < 0 || rid >= n) continue;
			
			int lx = req[rid].lx, ly = req[rid].ly;
			req[rid].q = min(req[rid].q, max(0.0L, BW[lx][ly][(s.t%10)] - bw[lx][ly]));

			if(req[rid].q > EPS){ // accepted Treq
				for(int i = 0; i < n; i++)
					if(req[i].fid == fid)
						st.set(i,i+1, -req[i].score);

				bw[lx][ly] += req[rid].q;
				updateS(sh, req[rid]);
			}else{ // rejected Treq
				st.set(rid,rid+1, -req[rid].score);
			}
		}
		sh.t++;
		dq.push_back(move(sh));
	}
}

// beam search
State solve(const State& s0){
	deque<State> dq; dq.push_back(s0);
	for(int t = s0.t; t < T; t++){

		// process top K states
		int k = min(K, (int)dq.size());
		for(int i = 0; i < k; i++){
			processState(dq.front(), dq);
			dq.pop_front();
		}

		sort(dq.begin(), dq.end()); // TODO: optimize this if TLE
		dq.resize(min(K, (int)dq.size()));
	}
	return dq.front();
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> M >> N >> F >> T;
	State s0 = {};

	// uavs
	BW.resize(M, vector<vector<double>>(N, vector<double>(10, 0.0L)));
	for(int i = 0; i < M*N; i++){
		int x,y,phi; double B;
		cin >> x >> y >> B >> phi;
		for(int t = 0; t < 10; t++) BW[x][y][t] = getBW(phi,B,t);
	}

	//flows
	for(int i = 0; i < F; i++){
		int id,ax,ay,t,m1,n1,m2,n2; double Q;
		cin >> id >> ax >> ay >> t >> Q >> m1 >> n1 >> m2 >> n2;
		s0.flows.emplace_back(Flow{id,m1,n1,m2,n2,ax,ay,-1,-1,t,0,Q,Q}); QT += Q;
	}
	sort(s0.flows.begin(), s0.flows.end());

	State s = solve(s0);

	cout << fixed << setprecision(7);
	for(const auto& flow : s.flows)
		cout << flow;
	cout << s.score << endl;
}
