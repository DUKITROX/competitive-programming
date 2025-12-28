#pragma GCC optimize("Ofast", "unroll-loops", "inline")
#include <bits/stdc++.h>
using namespace std;

//#define double long double

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 
#define urd(a,b) uniform_real_distribution<double>(a, b)(rng)

inline int mdist(int ax, int ay, int lx, int ly){return abs(ax-lx) + abs(ay-ly);}
inline double getBW(int phi, double B, int t){t += phi; t %= 10;if (t <= 1 || t >= 8) return 0.0;else if (t == 2 || t == 7) return B / 2.0;else return B;}

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
	
	State() : t(0), score(10.0), it(0){}
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
	bool operator<(const Treq& other) const {return fid < other.fid || fid == other.fid && score < other.score;}
};

const double inf = numeric_limits<double>::max();
struct Node { // [,)
	Node *l = 0, *r = 0;
	int lo, hi;
    double mset = inf, madd = 0.0, val = 0.0;
	Node(int lo,int hi):lo(lo),hi(hi),val(0.0){} // Large interval of -inf
	Node(vector<Treq>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = l->val + r->val;
		}
		else val = v[lo].score;
	}
	~Node(){
		if (l) { delete l; l = nullptr; }
		if (r) { delete r; r = nullptr; }
	}
	double query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void set(int L, int R, double x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = x, madd = 0, val = x*(hi - lo);
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
		}
	}
	void add(int L, int R, double x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x*(hi - lo);
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = l->val + r->val;
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
    int lower_bound(double v){
        int L = 0, R = hi-1, m, ans=0;
        while(L <= R){
            m = L + (R-L)/2;
			double res = query(0,m+1);
            if(v <= res) {
                ans = m;
                R = m-1;
            }else{
                L = m+1;
            }
        }
        return ans;
    }
};

constexpr int K = 2, H = 2; // states per timeslot & children per state

constexpr double EPS = 1e-9;
int M,N,F,T; double QT=0.0, TEMP=0.5;
vector<vector<vector<double>>> BW;

// updates State with Treq
void updateS(State& s, Treq& tr){
	s.flows[tr.fid].sched.emplace_back(tuple<int,int,int,double>{s.t, tr.lx, tr.ly, tr.q});
	if ((s.flows[tr.fid].q -= tr.q) < EPS)
		s.actf.erase(tr.fid);

	s.score += 40.0*tr.q/QT;
	s.score += 20.0*tr.q/QT*10/(10+s.t);
	s.score += 30.0*tr.q/QT*pow(2,-0.1*tr.d);
	s.score += 10.0*s.flows[tr.fid].Q/QT * (1.0/tr.k - 1.0/max(1, s.flows[tr.fid].k));

	s.flows[tr.fid].k = tr.k;
	s.flows[tr.fid].lx = tr.lx;
	s.flows[tr.fid].ly = tr.ly;
}

// IMP : evaluates Treq 
void processTreq(State& s, Treq& tr){
	int d = tr.d = mdist(s.flows[tr.fid].ax, s.flows[tr.fid].ay, tr.lx, tr.ly);
	int k = tr.k = s.flows[tr.fid].k + !(s.flows[tr.fid].lx == tr.lx && s.flows[tr.fid].ly == tr.ly);

	double s1 = (40.0 * tr.q) / s.flows[tr.fid].Q;
	double s2 = ((20.0 * tr.q) / s.flows[tr.fid].Q) * (10.0 / (s.t + 10.0));
	double s3 = ((30.0 * tr.q) / s.flows[tr.fid].Q) * pow(2.0, -0.1*d);
	double s4 = (10.0 / k);
	tr.score = s1 + s2 + s3 + s4;
	tr.score = exp(tr.score / TEMP);
}

// IMP : processes State
void processState(State& s, deque<State>& dq){
	vector<vector<double>> bw(M,vector<double>(N,0.0));
	vector<Treq> req;
	while(s.it < F && s.flows[s.it].t0 <= s.t) s.actf.insert(s.it++);
	
	for(const int& i : s.actf)
		for(int lx = s.flows[i].m1; lx <= s.flows[i].m2; lx++)
			for(int ly = s.flows[i].n1; ly <= s.flows[i].n2; ly++){
				req.emplace_back(Treq{i,lx,ly,s.flows[i].q});
				processTreq(s, req.back());
			}

    int n = req.size();
	if(!n){
		s.t++;
		dq.push_back(move(s));
		return;
	}

	sort(req.begin(), req.end());
    unordered_map<int, pair<int,int>> lim; // [,)
    for(auto& e : s.actf){
        int l = upper_bound(req.begin(), req.end(), Treq{e,-1,-1,-1.0}) - req.begin();
        int r = upper_bound(req.begin(), req.end(), Treq{e+1,-1,-1,-1.0}) - req.begin();
        lim[e] = {l,r};
    }
	
	// process "hijos"
	for(int h = 0; h < H; h++){
        Node* st = new Node(req, 0, n);		
		State sh(s);
		vector<bool> processed((int)s.flows.size());

		while(st->query(0,n) > EPS){
            int rid = st->lower_bound(urd(0.0, st->query(0,n))); 
            if(rid < 0 || rid >= n) continue;
			int fid = req[rid].fid;
			
			int lx = req[rid].lx, ly = req[rid].ly;
			req[rid].q = min(req[rid].q, max(0.0, BW[lx][ly][(s.t%10)] - bw[lx][ly]));
            
			if(req[rid].q > EPS && !processed[fid]){ // accepted Treq
				st->set(lim[fid].first, lim[fid].second, 0.0);
				processed[fid]=true;
				//for(int i = 0; i < n; i++)
				//	if(req[i].fid == fid)
				//		st->set(i,i+1,0.0);
				bw[lx][ly] += req[rid].q;
				updateS(sh, req[rid]);
			}else{ // rejected Treq
				st->set(rid,rid+1,0.0);
			}
		}

		delete st;
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
	BW.resize(M, vector<vector<double>>(N, vector<double>(10, 0.0)));
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
}