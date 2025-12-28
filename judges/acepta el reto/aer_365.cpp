#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,j; cin >> n >> j; j--;
	queue<int> q;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		q.push(i==j?-a:a);
	}
	int res = 0;
	while(1){
		int u = q.front(); q.pop();
		res += 2;
		if(u>0){
			if(--u) q.push(u);
		}else{
			if(++u) q.push(u);
			else break;
		}
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

