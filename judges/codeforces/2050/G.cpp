#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int& sol, vector<bool>& vis, vector<vector<int>>& adj, vector<int>& deg){
	vis[u] = true;
	vector<int> arr; arr.push_back(deg[u]);
	for(auto v : adj[u])
		if(!vis[v])
			arr.push_back(dfs(v,sol,vis,adj,deg) + deg[u] - 2);
	sort(arr.begin(), arr.end(), greater<>());
	sol = max({sol, arr[0], (arr.size() > 1 ? arr[0] + arr[1] - deg[u] : 0)});
	return arr[0];
}

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	vector<int> deg(n,0);
	vector<bool> vis(n, false);
	for(int i = 0; i < n-1; i++){
		int a,b; cin >> a >> b; a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		++deg[a];++deg[b];
	}
	int sol = -1;
	dfs(0, sol, vis, adj, deg);
	cout << sol << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
