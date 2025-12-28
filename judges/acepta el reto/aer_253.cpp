#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
	int n,k,s,e; while(cin >> n >> k >> s >> e && (n || k || s || e)){
		set<int> se;
		vector<vector<int>> adj(n*n+1);
		for(int i = 0; i < s+e; i++){
			int u,v; cin >> u >> v;
			adj[u].push_back(v);
			se.insert(u);
		}

		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; q.push({0,1});
		vector<int> d(n*n+1,INF),p(n*n+1,-1); d[1] = 0; 

		while(d[n*n] == INF){
			int dv = q.top().first, u = q.top().second; q.pop();
			if(dv!=d[u]) continue;
			if(!se.count(u)){
				for(int i = 1; i <= k; i++){
					int v = min(n*n,u+i);
					if(d[u]+1 < d[v]){
						p[v] = u;
						d[v] = d[u]+1;
						q.push({d[v],v});
					}
				}
			}
			for(auto v : adj[u]){
				if(d[u] < d[v]){
					p[v] = u;
					d[v] = d[u];
					q.push({d[v],v});
				}
			}
		}
		cout << d[n*n] << "\n";
	}
}
/*
10 4 5 5
13 7
93 26
29 10
11 6
19 8
18 42
16 25
40 64
33 60
63 74
*/
