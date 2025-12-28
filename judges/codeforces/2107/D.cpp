#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct cmp{
	bool operator()(int a, int b) const {return a > b;}
};

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; i++){int u,v; cin >> u >> v;u--;v--; adj[u].push_back(v); adj[v].push_back(u);}

	bool available[200000]; fill(available, available+n, true);
	pair<int,int> D;
	vector<int>pa(n);

	auto dfs = [&](auto&& self, int u, int p, int h)->void{
		ckmax(D, {h,u});
		pa[u] = p;
		for(const auto& v : adj[u]){
			if(v != p && available[v]){
				self(self, v, u, h+1);
			}
		}
	};

	int cont = 0;
	auto clear = [&](int u){
		while(u >= 0){
			available[u] = false;
			u = pa[u];
		}
	};

	vector<pair<int,pair<int,int>>> SOL;
	int cont2 = 0;
	while(1){
		cont2++;
		bool p = false;
		for(int i = 0; i < n; i++) p |= available[i];
		if(!p) break;
		for(int i = 0; i < n; i++){
			if(available[i]){
				D = {-1,-1};
				dfs(dfs, i, -1, 1);
				int u = D.second; D = {1,u}; pa[D.second] = -1;
				dfs(dfs, D.second, -1, 1);
				int v = D.second;
				SOL.push_back({D.first,{max(u,v)+1, min(u,v)+1}});
				clear(v);
			}
		}
	}
	sort(SOL.begin(), SOL.end(), greater<>());
	for(auto& e : SOL) cout << e.first << " " << e.second.first << " " << e.second.second << " ";
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	auto start = chrono::high_resolution_clock::now();
	int tt; cin >> tt; while(tt--) solve();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	#ifdef LOCAL
	cout << setprecision(3) << fixed << "Time: " << elapsed_seconds.count() << " seconds\n";
	#endif
}
