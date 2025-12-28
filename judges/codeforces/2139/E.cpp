#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,k; cin >> n >> k;
	vector<int> arr(n-1), h(n), d(n,-1); cin >> arr; d[0] = 0; h[0] = 1;
	vector<vector<int>> adj(n); for(int i = 0; i < n-1; i++) adj[arr[i]-1].push_back(i+1);
	queue<int> q; q.push(0);
	int H = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(!adj[u].size()) H = d[u];
		for(auto& v : adj[u]){
			d[v] = d[u] + 1;
			h[d[v]]++;
			q.push(v);
		}
	}
	bitset<20> bs, un; bs.set(k);
	un = (1LL<<(n-k+1))-1;
	for(int i = 0; i <= H; i++){
		bs |= (bs>>h[i]);
		bs &= (un>>h[i]);
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

