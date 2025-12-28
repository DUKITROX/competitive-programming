#include <bits/stdc++.h>
using namespace std;

int Dfs(int u, int p, vector<bool>& vis, vector<vector<int>>& adj){
	vis[u] = true;
	int res = 1;
	for(auto v : adj[u]){
		if(!vis[v]) res += Dfs(v,u,vis,adj);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; while(cin >> n){
		int m; cin >> m;
		vector<vector<int>> adj(n); for(int i = 0; i < m; i++){
			int u,v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<bool> vis(n); 
		cout << (Dfs(0, -1, vis, adj) == n && m==n-1 ? "SI" : "NO" ) << "\n";
	}
}
