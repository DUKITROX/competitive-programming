#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> plo(n);
	vector<pair<int,int>> arr(n); for(int i = 0; i < n; i++){cin >>arr[i].first; arr[i].second = i;plo[i]=arr[i].first;}
	sort(arr.begin(),arr.end());
	int h = -1, m = 0, M = 0, ind=0;

	vector<vector<int>> dp(n, vector<int>(n,0));

	for(int i = 0; i < n; i++){
		if(arr[i].first == h){
			for(int j = ind; j <= i; j++){
				dp[i][arr[i].second-arr[j].second] = dp[j][arr[i].second-arr[j].second] + 1;
				M = max(M, dp[i][arr[i].second-arr[j].second]);
			}
		}else{
			h = arr[i].first;
			ind = i;
		}
	}

	cout << M+1 << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
