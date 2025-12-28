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

struct po{
	int g;
	int d;
	int x;
};
int dp[5005][25][2];
po p[5005][25][2];

void solve(){
	int n,k; cin >> n >> k; vector<pair<int,int>> arr(n); 
	for(int i = 0; i < n; i++){cin >> arr[i].first; arr[i].second = i;}
	sort(arr.begin(),arr.end());

	for(int i = 0; i < 5005; i++) for(int j = 0; j < 25; j++) dp[i][j][0] = dp[i][j][1] = LINF; 
	for(int i = 0; i < 5005; i++) for(int j = 0; j < 25; j++) p[i][j][0] = p[i][j][1] = {-1,-1,-1}; 
	dp[n-1][k][1] = 0; 

	for(int i = n-2; i >= 0; i--){
		for(int l = 0; l < k; l++){
			int acum1 = arr[i].first*arr[i].first;
			int acum2 = -2*arr[i].first;
			for(int j = i+1; j < n; j++){
				if(ckmin(dp[i][l][0], dp[j][l+1][1] + acum1 + acum2*arr[j].first + arr[j].first*arr[j].first*(j-i)))
					p[i][l][0] = {j,l+1,1};
				acum1 += arr[j].first*arr[j].first;
				acum2 += -2*arr[j].first;
			}

			if(l){
				dp[i][l][1] = min(dp[i+1][l][0], dp[i+1][l+1][1]);
				if(dp[i+1][l][0] < dp[i+1][l+1][1]) p[i][l][1] = {i+1,l,0};
				else p[i][l][1] = {i+1,l+1,1};
			}
		}
	}

	vector<int> sol(n); 
	po w = dp[0][0][0] < dp[0][1][1] ? po{0,0,0} : po{0,1,1};
	while(w.g != -1){
		if(w.x)
			sol[arr[w.g].second] = arr[w.g].first;
		else
			for(int i = w.g; i < p[w.g][w.d][w.x].g; i++) 
				sol[arr[i].second] = arr[p[w.g][w.d][w.x].g].first;
		w = p[w.g][w.d][w.x];
	}
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}
