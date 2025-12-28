#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	priority_queue<int> pq;
	int n; cin >> n;
	int cost = 0;
	for(int i = 0; i < n; i++){
		int a; cin >> a; pq.push(a);
	}
	while(pq.size() > 1){
		int u = pq.top(); pq.pop(); int v = pq.top(); pq.pop();
		cost += max(u,v);
		pq.push(0);
	}
	cout << cost << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

