#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

struct Line {
	mutable int k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(int x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const int inf = 1e18;
	int div(int a, int b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(int k, int m) { //k*x + m
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	int query(int x) {
		if(empty()) return 0;
		//assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n); cin >> a >> b;
	vector<vector<int>> adj(n);
	vector<LineContainer> cvx(n);
	for(int i = 0; i < n-1; i++){
		int u,v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> dp(n), ind(n); iota(ind.begin(), ind.end(), 0);
	auto Dfs = [&](auto && self, int u, int p)->void{
		for(auto v : adj[u]){
			if(v != p){
				self(self, v, u);
				for(auto e : cvx[ind[v]]) cvx[ind[u]].add(e.k, e.m);
			}
		}
		dp[u] = -cvx[ind[u]].query(a[u]);
		cvx[ind[u]].add(-b[u], -dp[u]);
	};
	Dfs(Dfs,0,-1);
	cout << dp << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

