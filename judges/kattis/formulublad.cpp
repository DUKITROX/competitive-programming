#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,L; cin >> n >> L;
	vector<pair<int,int>> arr(n+1);
	for(int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;

	vector<vector<int>> dp(n+1, vector<int>(L+1, 0));
	vector<int> p(n+1);

	int sol = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= L; j++){
			if(j - arr[i].first >= 0)
				ckmax(dp[i][j], dp[i-1][j - arr[i].first] + arr[i].second);
			ckmax(dp[i][j], dp[i-1][j]);
			ckmax(sol, dp[i][j]);
		}	
	}

	vector<int> ind;
	int m = sol;
	for(int i = n; i > 0; i--){
		for(int j = 0; j <= L; j++){
			if(dp[i][j] == m){
				if(dp[i][j] != dp[i-1][j]){
					ind.push_back(i-1);
					m = dp[i-1][j - arr[i].first];
				}
				continue;
			}
		}
	}

	cout << ind.size() << " " << sol << "\n";
	for(int i = 0; i < ind.size(); i++)
		cout << ind[i] << " \n"[i == ind.size()-1];
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
