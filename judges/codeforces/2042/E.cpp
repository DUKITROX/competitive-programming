#include <bits/stdc++.h>
using namespace std;

int n;
int tam(int u, int p, vector<vector<int>>& adj, set<int>& res, set<int>& num, vector<int>& a){
	int tot = 0;
	bool pos = false;
	for(auto v : adj[u]){
		int t;
		if(v != p){
			t = tam(v, u, adj, res, num, a);
			tot += t;
			pos = (t>=n);
		}
	}
	pos = (2*n-tot-1>=n);
	if(!pos){
		res.insert(u);
		num.insert(a[u]);
	}
}

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& d, set<int>& res, vector<int>& pa){
	for(auto v : adj[u]){
		if(v!=p && !res.count(v)){
			pa[v] = u;
			d[v] = max(d[u], v);
			dfs(v,u,adj,d,res,pa);
		}
	}
}

void fin(int u, vector<int>& pa, set<int>& res, set<int>& num, vector<int>& a){
	if(!res.count(u)){
		res.insert(u);
		num.insert(a[u]);
		if(pa[u] != -1)
			fin(pa[u], pa, res, num, a);
	}
}

void solve(){
	cin >> n;
	vector<int> a(2*n); for(int i = 0; i < 2*n; i++) cin >> a[i];
	vector<vector<int>> adj(2*n); for(int i = 0; i < 2*n-1; i++){int a,b; cin>>a>>b;adj[--a].push_back(--b);adj[b].push_back(a);}

	set<int> res, num, rap; tam(0,-1,adj,res,num,a);
	
	if(res.size() == 0){
		// TODO: tenemos problema aqui!
		cout << "MEHH\n";
		return;
	}
	vector<int> d(2*n,0), pa(2*n,-1);
	for(int i = 0; i < 2*n; i++){
		if(res.count(i))
			dfs(i,-1,adj,d,res,pa);
	}

	sort(d.begin(), d.end(), greater<int>());

	for(int i = 0; i < d.size(); i++){
		if(!num.count(a[d[i]])){
			if(!rap.count(a[d[i]])){
				rap.insert(a[d[i]]);
			}else{
				fin(i,pa,res,num,a);
			}
		}
	}
	cout << res.size() << "\n";
	for(auto e : res)
		cout << e << " ";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
