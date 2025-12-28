#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int tt; cin >> tt; while(tt--){
		int n; cin >> n;
		vector<vector<int>> adj(n+1);
		vector<int> deg(n+1);
		set<int> leaf, fnd, snd, imp;

		long long sum = 0;
		for(int i = 0; i < n-1; i++){
			int u,v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			deg[u]++; deg[v]++;
		}

		for(int i = 1; i <= n; i++) if(deg[i]==1) leaf.insert(i);

		for(auto e : leaf){
			imp.insert(e);
			for(auto v : adj[e]){
				fnd.insert(v);
				imp.insert(v);
			}
		}
		for(auto e : fnd){
			for(auto v : adj[e]){
				if(!leaf.count(v)){
					snd.insert(v);
				}
			}
		}

		int tot = n - imp.size();

		auto Dfs = [&](auto&& self, int u, int p=-1)->int{
			int res = (1-imp.count(u));
			for(auto v : adj[u]){
				if(v != p){
					int child = self(self, v, u);
					res += child;

					if(snd.count(u)){
						if(fnd.count(v)){
							sum += child;
						}
					}
				}
			}
			if(snd.count(u) && fnd.count(p)){
				sum += tot - res;	
			}
			return res;
		};
		sum += leaf.size()*(n-leaf.size());
		Dfs(Dfs,1);
		cout << sum << "\n";
	}
}
