#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t
const int MOD = 998244353LL;

void solve(){
	int n,m; cin >> n >> m;
	vector<int> r(n+1,0);
	for(int i = 0,f,s; i < m; i++) cin >> f >> s, ckmax(r[s],f);

	vector<int> dp(n+2); dp[1] = 2; int ind=1;
	vector<int> pref(n+2); pref[0] = dp[1];

	for(int i = 2; i <= n+1; i++){
		ckmax(ind, r[i]);
		dp[i] = pref[i-1] + MOD - pref[ind]; dp[i] %= MOD;
		pref[i] = pref[i-1] + dp[i]; pref[i] %= MOD;
	}
	cout << dp << "\n";
	cout << dp[n] << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

