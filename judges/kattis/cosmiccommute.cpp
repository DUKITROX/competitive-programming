#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int INF = 1e9;

void solve(){
	int n,m,k; cin >> n >> m >> k;
	set<int> s; for(int i = 0; i < k; i++){int a; cin >> a; a--; s.insert(a);}
	vector<vector<int>> adj(n+1); for(int i = 0; i < m; i++){int u,v; cin >> u >> v; u--; v--; adj[u].push_back(v); adj[v].push_back(u);}

	vector<int> d1(n+1,INF), d2(n+1,INF);  d1[n-1]=0; d2[0]=0;
	int64_t SUM = 0;
	queue<int> q; q.push(n-1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(s.count(u)) SUM += d1[u];
		for(auto v : adj[u]){
			if(d1[v] == INF){
				d1[v] = d1[u] + 1;
				q.push(v);
			}
		}
	}
	int64_t s1 = d1[0], s2 = INF;
	q.push(0);while(!q.empty()){
		int u = q.front(); q.pop();
		if(s.count(u)) ckmin(s2, d2[u]*(k-1) + SUM - d1[u]);
		for(auto v : adj[u]){
			if(d2[v] == INF){
				d2[v] = d2[u] + 1;
				q.push(v);
			}
		}
	}
	ckmin(s2, (k-1)*s1);
	cout << s2/gcd(s2,k-1) << "/" << (k-1)/gcd(s2,k-1) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}

