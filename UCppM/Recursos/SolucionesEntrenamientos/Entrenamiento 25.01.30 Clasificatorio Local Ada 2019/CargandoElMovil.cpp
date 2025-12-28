#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int C,F; while(cin >> C >> F){
		vector<vector<int>> arr(F, vector<int>(C));
		for(int i = 0; i < F; i++) for(int j = 0; j < C; j++) cin >> arr[i][j];

		auto check = [&](int f)->bool{
			f-=2;
			vector<vector<int>> dp(F, vector<int>(C,-INF));
			dp[0][0] = f;
			for(int i = 1; i < C; i++) if(dp[0][i-1] + arr[0][i] >= 0) dp[0][i] = dp[0][i-1] + arr[0][i];
			for(int i = 1; i < F; i++) if(dp[i-1][0] + arr[i][0] >= 0) dp[i][0] = dp[i-1][0] + arr[i][0];
			for(int i = 1; i < F; i++){
				for(int j = 1; j < C; j++){
					int val = max(dp[i-1][j], dp[i][j-1]) + arr[i][j];
					if(val >= 0) dp[i][j] = val;
				}
			}
			return dp[F-1][C-1] >= 0;
		};
		int l = 2, r = 1e9, m, ans = 1e9;
		while(l <= r){
			m = (l+r) / 2;
			if(check(m)) {r = m-1; ans = m;}
			else l = m+1;
		}
		cout << m << "\n";
	}
}
