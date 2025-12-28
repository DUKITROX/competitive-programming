#include <bits/stdc++.h>
using namespace std;

#define int128_t
int f,c;

bool comp(int i, int j){
	if(i&j) return false;
	int x = (~i)&(~j)&((1<<f)-1);
	if(x%3 != 0) return false;
	x /= 3;
	if((x & (x>>1)) != 0) return false;
	return true;
}

signed main(){
	cin >> f >> c;
	vector<vector<int>> dp(c+1, vector<int>(1<<f));
	dp[0][0] = 1;
	for(int k = 0; k < c; k++){
		for(int i = 0; i <= (1<<f)-1; i++){
			for(int j = 0; j <= (1<<f)-1; j++){
				if(comp(i,j)){
					dp[k+1][j] += dp[k][i];
				}
			}
		}
	}
	cout << dp[c][0] << "\n";
}
