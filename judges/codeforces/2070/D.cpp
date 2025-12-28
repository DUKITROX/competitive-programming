#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

void solve(){
	int n, h=0; cin >> n;
	vector<int> d(n), dp(n);
	vector<unordered_set<int>> D(n), adj(n);

	for(int i = 1; i < n; i++){
		int v; cin >> v; v--;
		adj[i].insert(v);
		adj[v].insert(i);
	}

	d[0] = 0; D[0].insert(0);
	auto Dfs = [&](auto&& self, int u, int p)->void{
		for(auto v : adj[u]){
			if(v != p){
				d[v] = d[u] + 1;
				h = max(h, d[v]);
				D[d[v]].insert(v);
				self(self, v, u);
			}
		}
	};
	Dfs(Dfs, 0, -1);

	auto dfs = [&](auto&& self, int u)->int{
		if(dp[u]) return dp[u];
		if(d[u] == h) return dp[u] = 1LL;

		int cont = 1;
		for(auto v : D[d[u]+1]){
			if(!adj[u].count(v) || u == 0LL)
				cont = (cont + self(self, v)%MOD)%MOD;
		}
		return dp[u] = cont;
	};
	dfs(dfs, 0);

	int res = 1;
	for(auto v : D[1])
		res = (res + dp[v]%MOD)%MOD;
	cout << res << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
