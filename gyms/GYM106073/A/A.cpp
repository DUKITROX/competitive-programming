#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n,m; cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m)); cin >> arr;
	int sum = 0;
	for(int i = 0; i < m; i++){
		int s = 1;
		for(int j = 0; j < n; j++){
			ckmax(s, arr[j][i]);
		}
		sum += s;
	}
	cout << sum << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

