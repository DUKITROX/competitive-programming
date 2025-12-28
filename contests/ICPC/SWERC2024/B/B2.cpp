#pragma GCC optimize ("03")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<typename T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

constexpr int LINF = 1e18;
int dp[5005][25][2];
map<pair<int,pair<int,int>>,pair<int,pair<int,int>>> p;
map<pair<int,pair<int,int>>,int> v;

void solve(){
	int n,k; cin >> n >> k;
	vector<int> arr(n); cin >> arr; sort(arr.begin(), arr.end());

	for(int i=0;i<5005;i++)for(int j=0;j<25;j++)dp[i][j][0]=dp[i][j][1]=LINF; dp[n-1][k][1] = 0; 

	for(int i = n-2; i >= 0; i--){
		for(int j = 0; j < k; j++){
			int acum = 0;
			for(int l = i+1; l < n; l++){
				acum += (arr[l]-arr[i])*(arr[l]-arr[i]);
				if(ckmin(dp[i][j][0], dp[l][j+1][1] + acum){
					p[make_pair(i, make_pair(j,0))] = {l,{j+1,1}};
					v[make_pair(i, make_pair(j,0))] = arr[l];
				}
			}
			v[make_pair(i, make_pair(j,1))] = arr[i];
			dp[i][j][1] = min(dp[i+1][j][0], dp[i+1][j+1][1]);
			if(dp[i+1][j][0] < dp[i+1][j+1][1]){
				p[make_pair(i, make_pair(j,1LL))] = make_pair(i+1,make_pair(j,0LL));
			}else{
				p[make_pair(i, make_pair(j,1))] = make_pair(i+1, make_pair(j+1,1));
			}
		}
	}

	vector<int> sol(n);
	pair<int,pair<int,int>> v = dp[0][0][0] < dp[0][1][1] ? make_pair(0,make_pair(0,0)) : make_pair(0,make_pair(1,1));
	cout << min(dp[0][0][0], dp[0][1][1]) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}


