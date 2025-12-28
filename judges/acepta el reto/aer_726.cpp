#include <bits/stdc++.h>
using namespace std;

void k1(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& lis){
	vis[u] = true;
	for(auto v : adj[u])
		if(!vis[v]) k1(v,adj,vis,lis);
	lis.push_back(u);
}
int k2(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& cc, int comp){
	vis[u] = true;
	cc[u] = comp;
	int res = 1;
	for(auto v : adj[u])
		if(!vis[v]) res += k2(v,adj,vis,cc,comp);
	return res;
}
void dfs(int u, vector<set<int>>& comp, vector<bool>& vi, vector<int>& siz, vector<int>& a, vector<int>& b){
	vi[u] = true;
	if(comp[u].empty() && siz[u]==1) a[u] = 1;
	if(siz[u]>1) b[u] = 1;

	for(auto v : comp[u]){
		if(!vi[v]) dfs(v,comp,vi,siz,a,b);
		a[u] |= a[v];
		b[u] |= b[v];
	}
}

int main(){
	int n,m; while(cin >> n >> m){
		vector<vector<int>> adj(n), adjt(n);
		for(int i = 0; i < m; i++){
			int u,v; cin >> u >> v; u--;v--;
			adj[v].push_back(u);
			adjt[u].push_back(v);
		}
		vector<int> lis, cc(n);
		vector<bool> vis(n,false);
		for(int i = 0; i < n; i++)
			if(!vis[i]) k1(i,adj,vis,lis);

		fill(vis.begin(),vis.end(),false);
		int cont = 0;
		vector<int> siz;

		for(int i = n-1; i >= 0; i--){
			if(!vis[lis[i]]) {
				int r = k2(lis[i],adjt,vis,cc,cont++);
				siz.push_back(r);
			}
		}

		vector<set<int>> comp(cont);
		for(int i = 0; i < n; i++){
			for(auto v : adj[i])
				if(cc[i]!=cc[v])
					comp[cc[i]].insert(cc[v]);
		}

		vector<int> a(cont), b(cont);
		vector<bool> vi(cont,false);

		for(int i = 0; i < cont; i++){
			if(!vi[i]) dfs(i,comp,vi,siz,a,b);
		}
		int A=0,B=0,C=0;
		for(int i = 0; i < cont; i++){
			if(a[i]&&b[i]) C += siz[i];
			else if(a[i]) A += siz[i];
			else B += siz[i];
		}
		cout << A << " " << B << " " << C << "\n";
	}
}
