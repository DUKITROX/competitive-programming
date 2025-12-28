#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

const int INF = 1e9;

void solve(){
	int n,K,sol=0; cin >> n >> K;
	vector<int> arr(n),pref(n+1); cin >> arr;

	pref[0] = arr[0]; for(int i = 1; i < n; i++) pref[i] = max(pref[i-1], arr[i]); 

	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(K+1, vector<int>(K+1, -INF)));
	dp[0][0][K] = 0;

	for(int i = 0; i < n; i++){
		for(int m = 0; m <= K; m++){
			for(int k = 0; k <= K; k++){	
				//estoy pensando que pongo en la pos "i" 
				//el max hasta ahora es "m"
				//tengo "k" monedas libres
				ckmax(dp[i+1][m][k], dp[i][m][k] + m); // no pongo ninguna en esta
				if(i && pref[i] != pref[i-1])
					for(int l = pref[i-1]+1; l <= min(pref[i], k); l++)
						ckmax(dp[i+1][l][k-l], dp[i][m][k] + l);
				else if(!i){
					for(int l = 0; l <= min(arr[0], k); l++)
						ckmax(dp[i+1][l][k-l], dp[i][m][k] + l);
				}
			}
		}
	}
	for(int i = 0; i <= K; i++)
		for(int j = 0; j <= K; j++)
			ckmax(sol, dp[n][i][j]);
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

