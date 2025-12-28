#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define int long long
const int INF = 1e18;

void solve(){
	int n,k; cin >> n >> k;
	string s,sol;  cin >> s;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];

	int lMax = -INF, gMax = -INF, tMax = -INF;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			lMax = max(lMax+arr[i], arr[i]);
			ckmax(gMax, lMax);
		}else{
			lMax = -INF;
			tMax = INF;
		}
	}
	ckmax(tMax,gMax);

	cin >> sol;
	if(sol == "NO"){
		if(gMax <= k && k <= tMax) cout << "Error! si hay solucion\n", exit(1);
	}else{
		vector<int> sola(n); for(int i = 0; i < n; i++) cin >> sola[i];
		lMax=gMax=-INF;
		for(int i = 0; i < n; i++){
			lMax = max(lMax+sola[i], sola[i]);
			ckmax(gMax,lMax);
			if(s[i] == '1' && arr[i] != sola[i]) cout << "Error! bad vector output\n", exit(1);
			else if(abs(arr[i]) > INF) cout << "Error! overlow solution\n", exit(1);
		}
		if(gMax != k) cout << "Error! max subarray sum is " << gMax << "\n", exit(1);
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
	cout << "OK\n";
}

