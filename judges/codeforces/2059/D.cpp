#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,s1,s2,m1,m2; cin >> n >> s1 >> s2 >> m1;
	vector<set<int>> adj1(n), adj2(n);
	vector<pair<int,int>> edg1, edg2;
	for(int i = 0; i < m1; i++){
		int u,v; cin >> u >> v; u--; v--;
		adj1[u].insert(v);
		adj1[v].insert(u);
		edg1.push_back({u,v});
	} cin >> m2 ;
	for(int i = 0; i < m2; i++){
		int u,v; cin >> u >> v; u--; v--;
		adj2[u].insert(v);
		adj2[v].insert(u);
		edg2.push_back({u,v});
	}

	vector<vector<int>> d(n, vector<int>(n, 1e18)); d[s1-1][s2-1] = 0;
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
	pq.push({0,{s1-1,s2-1}});

	while(!pq.empty()){
		int du = pq.top().first;
		pair<int,int> u = pq.top().second;
		pq.pop();
		if(du != d[u.first][u.second]) continue;

		for(auto e1 : adj1[u.first]){
			for(auto e2 : adj2[u.second]){
				if(d[e1][e2] > du + abs(e1-e2)){
					d[e1][e2] = du + abs(e1-e2);
					pq.push({d[e1][e2], {e1,e2}});
				}
			}
		}
	}

	int sol = 1e18;
	for(int i = 0; i < m1; i++){
		int u = edg1[i].first, v = edg1[i].second;
		if(!adj2[u].count(v)) continue;
		sol = min({sol, d[u][u], d[v][v]});
	}
	cout << (sol==1e18?-1:sol) << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
