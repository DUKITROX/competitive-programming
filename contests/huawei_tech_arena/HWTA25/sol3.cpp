#include <bits/stdc++.h>
using namespace std;

#define double long double

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 
#define urd(a,b) uniform_real_distribution<double>(a, b)(rng)

inline int mdist(int ax, int ay, int lx, int ly){return abs(ax-lx) + abs(ay-ly);}
inline double getBW(int phi, double B, int t){t += phi; t %= 10;if (t <= 1 || t >= 8) return 0.0L;else if (t == 2 || t == 7) return B / 2.0L;else return B;}

template<typename T>
struct FT {
	vector<T> s;
	FT(int n) : s(n) {}
	void update(int pos, T dif) { // a[pos] += dif
		for (; pos < (int)s.size(); pos |= pos + 1) s[pos] += dif;
	}
	T query(int pos) { // sum of values in [0, pos)
		T res = 0.0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(T sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0.0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= (int)s.size() && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
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
	bool operator<(const Treq& other) const {return score > other.score;}
};

constexpr int K = 5, H = 20; // states per timeslot & children per state
constexpr double EPS = 1e-9;
int M,N,F,T; double QT=0.0L, TEMP=0.5;
vector<vector<vector<double>>> BW;

// updates State with Treq
void updateS(State& s, Treq& tr){
	s.flows[tr.fid].sched.emplace_back(tuple<int,int,int,double>{s.t, tr.lx, tr.ly, tr.q});
	if ((s.flows[tr.fid].q -= tr.q) < EPS)
		s.actf.erase(tr.fid);

	s.score += 40.0L*tr.q/QT;
	s.score += 20.0L*tr.q/QT*10/(10+s.t);
	s.score += 30.0L*tr.q/QT*pow(2,-0.1*tr.d);
	s.score += 10.0L*s.flows[tr.fid].Q/QT * (1.0L/tr.k - 1.0L/max(1, s.flows[tr.fid].k));

	s.flows[tr.fid].k = tr.k;
	s.flows[tr.fid].lx = tr.lx;
	s.flows[tr.fid].ly = tr.ly;
}

// IMP : evaluates Treq 
void processTreq(State& s, Treq& tr){
	int d = tr.d = mdist(s.flows[tr.fid].ax, s.flows[tr.fid].ay, tr.lx, tr.ly);
	int k = tr.k = s.flows[tr.fid].k + !(s.flows[tr.fid].lx == tr.lx && s.flows[tr.fid].ly == tr.ly);

	double s1 = 0.4L * tr.q / s.flows[tr.fid].Q;
	double s2 = 0.2L * tr.q / s.flows[tr.fid].Q * 10.0L / (s.t + 10.0L);
	double s3 = 0.3L * tr.q / s.flows[tr.fid].Q * pow(2.0L, -0.1*d);
	double s4 = 0.1L / k;

	tr.score = s1 + s2 + s3 + s4;
	tr.score = exp(tr.score / TEMP);
}

// IMP : processes State
void processState(State& s, deque<State>& dq){
	vector<vector<double>> bw(M,vector<double>(N,0.0L));
	vector<Treq> req;
	while(s.it < F && s.flows[s.it].t0 <= s.t) s.actf.insert(s.it++);

	for(const int& i : s.actf)
		for(int lx = s.flows[i].m1; lx <= s.flows[i].m2; lx++)
			for(int ly = s.flows[i].n1; ly <= s.flows[i].n2; ly++){
				req.emplace_back(Treq{i,lx,ly,s.flows[i].q});
				processTreq(s, req.back());
			}
	//sort(req.begin(), req.end());

	int n = req.size();
	FT<double> ft(n);
	
	// process "hijos"
	for(int h = 0; h < H; h++){
		for(int i = 0; i < n; i++)
			ft.update(i, req[i].score);		
		State sh(s);

		while(ft.query(n) > EPS){
			int rid = ft.lower_bound(urd(0.0L, ft.query(n))); 
			int fid = req[rid].fid;
			if(rid < 0 || rid >= n) continue;
			
			int lx = req[rid].lx, ly = req[rid].ly;
			req[rid].q = min(req[rid].q, max(0.0L, BW[lx][ly][(s.t%10)] - bw[lx][ly]));

			if(req[rid].q > EPS){ // accepted Treq
				for(int i = 0; i < n; i++)
					if(req[i].fid == fid)
						ft.update(i, -req[i].score);
				bw[lx][ly] += req[rid].q;
				updateS(sh, req[rid]);
			}else{ // rejected Treq
				ft.update(rid, -req[rid].score);
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
