#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	const int N = 100;
	int dp[100][100][3] = {0}; // 0:=unlocked 1:=locked but shadowed 2:=actually locked lmao
	dp[0][0][1] = dp[0][0][0] = dp[0][1][2] = dp[1][1][2] = 1;
	//for(int j = 2; j < N; j++) dp[0][j][0] = 0;
	//for(int i = 0; i < N; i++) dp[i][0][2] = dp[i][0][1] = 1;

	for(int i = 1; i < N; i++){
		for(int j = 0; j < N; j++){
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j][2];
			if(j) dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][2];
		}
	}

	int n,s; while(cin >> n >> s && n >= 0 && s >= 0){
		cout << dp[n-1][s][0] + dp[n-1][s][2] << "\n";
	}
}

