#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n; cin >> n; vector<int> h(n), dp(n); cin >> h;
	dp[0] = h[0]; dp[1] = h[0] + h[1] - 1;
	for(int i = 2; i < n; i++) dp[i] = min(dp[i-2] + h[i-1] + max(0LL, h[i]-i), dp[i-1] + h[i] -1);
	cout << dp.back() << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

