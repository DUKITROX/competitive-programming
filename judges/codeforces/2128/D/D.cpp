#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n; cin >> n; vector<int> arr(n); cin >> arr;
	vector<pair<int,int>> dp(n); dp[0] = {1,1};
	for(int i = 1; i < n; i++){
		dp[i].first+=1+(arr[i-1] < arr[i]);
		int j = arr[i-1] < arr[i] ? i-2 : i-1;
		if(j>=0){
			dp[i].first += dp[j].first;
			dp[i].second += dp[j].second;
		}
		dp[i].second += dp[i].first;
	}
	int sol = 0; for(auto& e : dp) sol += e.second;
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

