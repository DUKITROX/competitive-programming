#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n, T; cin >> n >> T;
	vector<pair<int,pair<int,int>>> info(n); 
	for(int i = 0; i < n; i++) cin >> info[i].first >> info[i].second.first >> info[i].second.second;
	vector<vector<int>> adj(n+2, vector<int>(n+2));
	for(int i = 0; i < n; i++) cin >> adj[i];

}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

