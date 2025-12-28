#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void solve(){
	int n,m,p; cin >> n >> m >> p;
	map<pair<int,int>, vector<pair<int,int>>> adj;
	map<pair<int,int>, bool> vis;
	int xa,ya; cin >> xa >> ya;
	int res = 1, node, edge, sloop;
	for(int i = 0; i < p; i++){
		int x,y; cin >> x >> y;
		if(abs(x-xa) + abs(y-ya) != 2) res = 0;
		if(x != xa && y != ya){
			adj[{x,ya}].push_back({xa,y});
			adj[{xa,y}].push_back({x,ya});
		}else if(x == xa)
			adj[{x,min(y,ya)+1}].push_back({x,min(y,ya)+1});
		else
			adj[{min(x,xa)+1,y}].push_back({min(y,ya)+1,y});
		xa = x; ya = y;
	}
	auto dfs = [&](auto&& self, pair<int,int> u)->void{
		vis[u] = true;
		edge += adj[u].size();
		node++;
		for(auto v : adj[u]){
			if(v == u) sloop = 1;
			if(!vis[v])	
				self(self, v);
		}
	};
	for(auto e : adj){
		if(!vis[e.first]){
			sloop = node = edge = 0;
			dfs(dfs, e.first);
			edge++;edge>>=1;
			if(edge > node) res = 0;
			else if(!sloop && edge == node) {res<<=1;res%=MOD;}
			else if(edge < node) {res*=node; res%=MOD;}
		}
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

