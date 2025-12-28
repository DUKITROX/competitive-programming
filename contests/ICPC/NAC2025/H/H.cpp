#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n, k; cin >> n >> k;
	vector<vector<int>> adj(n);
	vector<int> w(n),W(n); cin >> w;
	for(int i = 0; i < n-1; i++){
		int u,v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto dfs = [&](auto&& self, int u, int p)->void{
		if(w[u] != -1) W[u] += w[u];
		for(auto v : adj[u])
			if(v != p && w[v] != -1) W[u] += w[v];
		if(W[u] > k) {cout << "-1\n"; exit(0);}

		for(auto v : adj[u])
			if(v != p)
				self(self, v, u);

		if(w[u] == -1){
			int aux = max(W[u], p != -1 ? W[p] : 0);
			w[u] = k - aux;
			W[u] += w[u];
			if(p != -1) W[p] += w[u];
		}
	};
	dfs(dfs, 0, -1);
	cout << accumulate(w.begin(), w.end(), 0LL) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

