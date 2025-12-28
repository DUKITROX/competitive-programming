#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;

int rec(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& cost){
	if(dp[i][j] != -1) return dp[i][j];

	int val = 1e9;
	for(int I = i; I < j; I++){
		val = min(val, rec(i, I, dp, cost) + rec(I, j-1, dp, cost) + cost[I][j]);
	}

	return dp[i][j] = val;
}

signed main(){
	cin >> n; vector<pair<int,int>> arr(n);
	for(int i = 0; i < n; i++){cin >> arr[i].first; arr[i].second = i;}
	sort(arr.begin(), arr.end());
	vector<vector<int>> cost(n, vector<int>(n,1e9));

	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
			cost[j][i] = cost[i][j] = abs(arr[i].second - arr[j].second);

	vector<vector<int>> dp(n, vector<int>(n,-1));
	for(int i = 0; i < n; i++) dp[i][i] = 0;
	for(int i = 0; i < n-1; i++) dp[i][i+1] = cost[i][i+1];


	cout << rec(0,n-1,dp,cost) << "\n";
}
