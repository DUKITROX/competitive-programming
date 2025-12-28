#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define ll long long
#define int long long

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) { //k*x + m
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

struct node {
	int Tsum,L,R;
	LineContainer pref, suf, best;
	node() : Tsum(0), L(0), R(0){
		pref.add(0,0);
		suf.add(0,0);
		best.add(0,0);
	}
	node(int i, int e) : Tsum(e), L(i), R(i+1) {
		pref.add(1,e);
		suf.add(1,e);
		best.add(1,e);
	}
};

int X = 0;

template<typename T = int>
struct STree {
	using F = function<T(T&, T&)>;
	F f; vector<T> s; int n; T unit;
	STree(int n, F f = std::min, T def = INT_MAX) : s(2*n, def), n(n), f(f) , unit(def){}
	STree(const vector<int>& v, F f, T def) : n(v.size()) , f(f), unit(def){
		s.resize(2 * n);
		for (int i = 0; i < n; ++i) s[n + i] = T{i,v[i]};
		for (int i = n - 1; i > 0; --i) s[i] = f(s[2 * i], s[2 * i + 1]);
		s[0] = node{};
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	int query(int b, int e) { // query [b, e)
		vector<node*> l,r;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) l.push_back(&s[b++]);
			if (e % 2) r.push_back(&s[--e]);
		} reverse(r.begin(), r.end());

		int gMax=0,lMax=0;
		for(int i = 0; i < (int)l.size(); i++){
			gMax = max({gMax, l[i]->best.query(X), lMax + l[i]->pref.query(X)});
			lMax = max({l[i]->suf.query(X), lMax + l[i]->Tsum + X*(l[i]->R - l[i]->L)});
		}

		for(int i = 0; i < (int)r.size(); i++){
			gMax = max({gMax, r[i]->best.query(X), lMax + r[i]->pref.query(X)});
			lMax = max({r[i]->suf.query(X), lMax + r[i]->Tsum + X*(r[i]->R - r[i]->L)});
		}

		return gMax;
	}
};

void solve(){
	int n,q; cin >> n >> q;
	vector<int> arr(n); cin >> arr;

	auto f = [&](node &l, node &r)->node{
		node n = node{};
		n.L = l.L; n.R = r.R;
		n.Tsum = l.Tsum + r.Tsum;

		//prefix
		for(const auto &e : l.pref) n.pref.add(e.k, e.m);
		for(const auto &e : r.pref) n.pref.add(e.k + l.R - l.L, l.Tsum + e.m);

		//suffix
		for(const auto &e : r.suf) n.suf.add(e.k, e.m);
		for(const auto &e : l.suf) n.suf.add(e.k + r.R - r.L, r.Tsum + e.m);

		//best
		for(const auto &e : l.best) n.best.add(e.k, e.m);
		for(const auto &e : r.best) n.best.add(e.k, e.m);

		auto it = l.suf.begin(), jt = r.pref.begin();
		while(it != l.suf.end() && jt != r.pref.end()){
			n.best.add(it->k + jt->k, it->m + jt->m);

			if(abs(it->p - jt->p) < 1e-9) it++, jt++;
			else if(it->p < jt->p) ++it;
			else jt++;
		}

		return n;
	};
	STree<node> st(arr,f,node{});

	for(int i = 0; i < q; i++){
		string s; cin >> s;
		if(s == "ASSESS"){
			int l,r; cin >> l >> r;
			cout << st.query(--l, r) << "\n";
		}else{
			int x; cin >> x; X += x;
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}


