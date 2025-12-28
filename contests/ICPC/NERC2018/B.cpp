#include <bits/stdc++.h>
using namespace std;

int n,m,k; 
void dfs(int u, vector<bool>& vis, bool& cycle, vector<vector<int>>& adj, vector<int>& topo,set<int>& s){
	if(cycle) return;
	s.insert(u);
	vis[u] = true;
	for(auto v : adj[u]){
		if(s.count(v)) cycle = true;
		if(!vis[v]) dfs(v,vis,cycle,adj,topo,s);
	}
	s.erase(u);
	if(u != n) topo.push_back(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	vector<int> in_deg(n);
	vector<int> rank(n); for(int i = 0; i < n; i++) {cin >> rank[i];}
	vector<vector<int>> adj(n+1), fat(n); for(int i = 0; i < m; i++) {int u,v; cin >> u >> v; u--; v--; adj[u].push_back(v); in_deg[v]++; fat[v].push_back(u);}
	for(int i = 0; i < n; i++){if(in_deg[i] == 0) adj[n].push_back(i);}

	set<int> s; bool cycle = false;
	vector<bool> vis(n+1, false);
	vector<int> topo;
	dfs(n,vis,cycle,adj,topo,s);
	for(int i = 0; i < n; i++) if(!vis[i]) dfs(i,vis,cycle,adj,topo,s);

	if(cycle)
		cout << "-1\n";
	else{
		reverse(topo.begin(), topo.end());
		vector<int> prov(rank);
		for(int i = 0; i < n; i++){
			int m = k; for(auto v : fat[topo[i]]) m = min(m, prov[v]-1);
			if(m == 0) cycle = true;
			else if(rank[topo[i]] > m) cycle = true;
			else if(!rank[topo[i]]) prov[topo[i]] = m;
		}
		if(cycle){
			cout << "-1\n";
		}else{
			set<int> rks; for(int i = 1; i <= k; i++) rks.insert(i);
			for(int i = 0; i < n; i++) rks.erase(rank[i]);

			sort(topo.begin(), topo.end(),[&](int u, int v)->bool{
				if(!rank[u] && rank[v]) return false;
				if(rank[u] && !rank[v]) return true;
				return prov[u] > prov[v];
			});
			for(int i = n-1; i>= 0; i--){
				int m = 1; for(auto v : adj[topo[i]]) m = max(m, prov[v]+1);
				if(!rks.empty() && rks.lower_bound(m) != rks.end() && *rks.lower_bound(m) <= prov[topo[i]]) m = *rks.lower_bound(m);
				if(m > prov[topo[i]]) cycle = true;
				else if(!rank[topo[i]]) {
					prov[topo[i]] = m;
				}
				//cout << topo[i] << " : " << prov[topo[i]] << endl;
				rks.erase(prov[topo[i]]);
			}
			if(cycle || !rks.empty()){
				cout << "-1\n";
			}else{
				for(int i = 0; i < n; i++) cout << prov[i] << " \n"[i==n-1];
			}
		}
	}
}
