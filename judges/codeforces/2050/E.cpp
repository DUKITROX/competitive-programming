#include <bits/stdc++.h>
using namespace std;

void solve(){
	string a,b,c; cin >> a >> b >> c;
	vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

	for(int i = 0; i <= a.length(); i++){
		for(int j = 0; j <= b.length(); j++){
			if(!i && !j) dp[i][j] = 0;
			else if(!i) dp[i][j] = dp[i][j-1] + (b[j-1]!=c[j-1]);
			else if(!j) dp[i][j] = dp[i-1][j] + (a[i-1]!=c[i-1]);
			else dp[i][j] = min(dp[i-1][j] + (a[i-1]!=c[i+j-1]), dp[i][j-1] + (b[j-1]!=c[i+j-1]));
		}
	}

	cout << dp[a.length()][b.length()] << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
