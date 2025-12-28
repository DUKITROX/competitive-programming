#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define int int64_t
const int INF = 1e18;

void solve(){
	int n,m; cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n);
	vector<pair<pair<int,int>, int>> edges;
	for(int i = 0; i < m; i++){
		int u,v,d; cin >> u >> v >> d; u--; v--;
		adj[u].push_back({v,d});
		adj[v].push_back({u,d});
		edges.push_back({{u,v},d});
	}
	vector<int> d1(n,INF), d2(n,INF); d1[0] = d2[n-1] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		auto [du, u] = pq.top();  pq.pop();
		if(d1[u] != du) continue;
		for(auto [v, dv] : adj[u]){
			if(ckmin(d1[v], max(du,dv)))
				pq.push({d1[v], v});
		}
	}
	pq.push({0,n-1});
	while(!pq.empty()){
		auto [du, u] = pq.top();  pq.pop();
		if(d2[u] != du) continue;
		for(auto [v, dv] : adj[u]){
			if(ckmin(d2[v], max(du,dv)))
				pq.push({d2[v], v});
		}
	}
	int sol = INF;
	for(auto [uv,d] : edges){
		auto [u,v] = uv;
		ckmin(sol, d + min(max({d1[u], d2[v], d}), max({d1[v], d2[u], d})));
	}
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

