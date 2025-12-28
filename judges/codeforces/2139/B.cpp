#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n,m; cin >> n >> m;
	vector<int> arr(n); cin >> arr; sort(arr.begin(), arr.end());
	int64_t sol = 0, t = 1;
	if(m > n) sol += arr[0]*(m-n), t = m-n+1, m = n;
	sol += arr[n-m]; t++;
	for(int i = n-m+1; i < n; i++) sol += arr[i]*t, t++;
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

