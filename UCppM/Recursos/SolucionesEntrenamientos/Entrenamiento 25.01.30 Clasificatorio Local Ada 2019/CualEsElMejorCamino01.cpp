#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

signed main(){
	int n, m, k;
	while(cin >> n){
		cin >> m;
		vector<vector<pair<int,int>>> adj(n);
		for(int i = 0; i < m; i++){
			int u,v,d; cin >> u >> v >> d; u--; v--;
			adj[u].push_back({d,v});
			adj[v].push_back({d,u});
		}

		cin >> k; while(k--){
			int s,t; cin >> s >> t; s--; t--;

			vector<int> D(n,INF), p(n,INF), d(n,-1); D[s] = p[s] = d[s] = 0;
			priority_queue<pair<int,int>, vector<pair<int,int>>,
			greater<pair<int,int>>> pq; pq.push({0,s});

			while(!pq.empty()){
				int u = pq.top().second, du = pq.top().first; pq.pop();
				if(D[u] != du) continue;
				for(auto e : adj[u]){
					int dv = e.first, v = e.second;
					if(D[v] > D[u] + dv || D[v] == D[u] + dv && p[u]+1 < p[v]) {
						D[v] = D[u] + dv;
						p[v] = p[u] + 1;
						pq.push({D[v],v});
					}
				}
			}

			queue<int> q; q.push(s);
			while(!q.empty()){
				int u = q.front(); q.pop();
				for(auto e : adj[u]){
					int dv = e.first, v = e.second;
					if(d[v] == -1){
						d[v] = d[u] + 1;
						q.push(v);
					}
				}
			}

			if(D[t] >= INF) cout << "SIN CAMINO\n";
			else cout << D[t] << " " << (p[t] <= d[t] ? "SI" : "NO") << "\n";
		}
		cout << "----\n";
	}
	return 0;
}
