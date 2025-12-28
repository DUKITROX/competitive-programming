#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--){
		int n; cin >> n;
		vector<vector<int>> dp(n, vector<int>(2, 1));
		vector<vector<pair<int,int>>> acum(n, vector<pair<int,int>>(2));

		for(int i = 0; i < n; i++){
			char c1,c2; int a1,a2; cin >> c1 >> a1 >> c2 >> a2;
			if(c1 == '+') acum[i][0] = {0,a1};
			else acum[i][0] = {1,a1};
			
			if(c2 == '+') acum[i][1] = {0,a2};
			else acum[i][1] = {1,a2};
		}

		for(int i = n-1; i >= 0; i--){
			if(i < n-1) dp[i][0] = dp[i+1][0];
			if(i < n-1) dp[i][1] = dp[i+1][1];

			if(acum[i][0].first) dp[i][0] *= acum[i][0].second;
			if(acum[i][1].first) dp[i][1] *= acum[i][1].second;
		}

		int a = 1LL, b = 1LL;
		for(int i = 0; i < n; i++){
			int exa=0, exb=0;

			if(acum[i][0].first) exa = a*(acum[i][0].second-1);
			else exa = acum[i][0].second;

			if(acum[i][1].first) exb = b*(acum[i][1].second-1);
			else exb = acum[i][1].second;

			if(dp[i][0] > dp[i][1]) a += exa+exb;
			else b += exb+exa;
		}
		cout << a + b << "\n";
	}
}
