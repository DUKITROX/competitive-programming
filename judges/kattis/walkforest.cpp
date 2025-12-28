#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define int int64_t
const int64_t INF = 1e18;

void solve(){
	int n,m;
	while(1){
		cin >> n; if(!n) return; cin >> m;
		vector<vector<pair<int,int>>> adj(n); for(int i = 0; i < m; i++) {int u,v,d; cin >> u >> v >> d; u--; v--; adj[u].push_back({v,d}); adj[v].push_back({u,d});}
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
		vector<int64_t> d(n, INF); d[1] = 0; pq.push({0,1});
		while(!pq.empty()){
			int64_t du = pq.top().first, u = pq.top().second; pq.pop();
			if(du > d[u]) continue;
			for(auto e : adj[u]){
				int64_t dv = e.second, v = e.first;
				if(d[v] > dv + du){
					d[v] = dv+du;
					pq.push({d[v],v});
				}
			}
		}
		vector<int64_t> sol(n,-1); sol[0] = 1LL;
		auto dfs = [&](auto&& self, int u)->int{
			if(sol[u] != -1LL) return sol[u];
			int w = 0LL;
			for(auto e : adj[u]){
				int v = e.first;
				if(d[v] > d[u]){
					w += self(self, v);
				}
			}
			return (sol[u] = w);
		};
		cout << dfs(dfs,1) << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}

