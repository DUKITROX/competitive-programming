#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int64_t LINF = 1e18;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n;
	vector<int> arr(n+1), prefM(n+1, INF), prefS(n+1), minI;
	for(int i = 1; i <= n; i++) cin >> arr[i]; arr[0] = arr[1]-1;
	for(int i = 0; i <= n; i++) {
		prefM[i] = min(arr[i], i==n?INF:prefM[i+1]);
		prefS[i] = prefM[i] == arr[i] + (i==n?0:prefS[i+1]);
		if(i==n||prefM[i]!=prefM[i+1]) minI.push_back(i);
	} 

	vector<int> pref(n+1);
	for(int i = n; i >= 0; i--){
		
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

