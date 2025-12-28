#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve(){
	int n; cin >> n;
	vector<int> dp(4); dp[0] = 1;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		if(a == 2) {dp[2] <<= 1; dp[2]%=MOD;}
		dp[a] += dp[a-1];
		dp[a] %= MOD;
	}
	cout << dp[3] << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}
