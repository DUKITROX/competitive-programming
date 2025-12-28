#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
#define int int64_t

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int e,n; cin >> e >> n;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	vector<int> dp(e+1);
	for(int i = 0; i < n; i++) if(arr[i] <= e) dp[arr[i]] = 1;
	for(int i = 0; i <= e; i++)
		for(int j = 0; j < n; j++)
			if(i - arr[j] >= 0)
				dp[i] = (dp[i] + dp[i - arr[j]])%(1000000007LL);
	cout << dp[e] << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}

