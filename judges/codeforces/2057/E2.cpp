#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve(){
	int n,m,q; cin >> n >> m >> q;
	map<int, vector<pair<int,int>>> we; 
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++){
		int a,b,w; cin >> a >> b >> w; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		we[w].push_back({a,b});
	}

	int K = we.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 1e9)));

	vector<int> pos(K+1); int ind = 1;
	for(auto [f,s] : we){
		pos[ind++]= f;
	}

	for(int i = 0; i < n; i++){
		queue<int> q; q.push(i);
		dp[0][i][i] = 0;
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(auto v : adj[u]){
				if(dp[0][i][v] == 1e9){
					dp[0][i][v] = dp[0][i][u] + 1;
					q.push(v);
				}
			}
		}
	}

	for(int ind = 0; ind <= K; ind++){
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				dp[ind][i][j] = dp[ind-1][i][j];
				for(auto [a,b] : we[pos[ind]]){
					dp[ind][i][j] = min({dp[ind][i][j], dp[ind-1][a][i] + dp[ind-1][b][j], dp[ind-1][a][j] + dp[ind-1][b][i]});
					dp[ind][j][i] = dp[ind][i][j];
				}
			}
		}
	}

	for(int i = 0; i < q; i++){
		int s,t,k; cin >> s >> t >> k; s--; t--;
		int l = 1, r = K, ans;
		while(l <= r){
			int m = (l+r)/2;
			if(dp[m][s][t] >= k){
				l = m+1;
			}else{
				ans = m;
				r = m-1;
			}
		}
		cout << pos[ans] << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tt; cin >> tt; while(tt--) solve();
}
