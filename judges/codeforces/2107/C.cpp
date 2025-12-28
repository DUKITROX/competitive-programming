#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define int int64_t
const int INF = 1e18;

void solve(){
	int n,k; cin >> n >> k;
	string s; cin >> s;

	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	int lMax=-INF,gMax=-INF,tMax=-INF; 
	for(int i = 0; i < n; i++){
		if(s[i] == '1') {
			lMax = max(lMax+arr[i], arr[i]);
			ckmax(gMax,lMax);
		}else{
			lMax = -INF;
			tMax = INF;
		}
	}
	ckmax(tMax,gMax);
	if(k < gMax || k > tMax) cout << "NO\n";
	else{
		cout << "YES\n";
		int first=-1,second = n;
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				if(first == -1) first = i;
				else {if(second == n) second = i; arr[i] = -INF;}
			}
		}
		if(first != -1){
			lMax = -INF, gMax = -INF;
			for(int i = 0; i < first; i++){
				lMax = max(lMax+arr[i], arr[i]);
				ckmin(lMax, INF);
				ckmax(gMax,lMax);
			}
			int tot = max(lMax,0LL); gMax = lMax = -INF;
			for(int i = second-1; i > first; i--){
				lMax = max(lMax+arr[i], arr[i]);
				ckmin(lMax, INF);
				ckmax(gMax,lMax);
			}
			tot+=max(0LL,lMax);
			arr[first] = k-tot;
		}
		for(int i = 0; i < n; i++) cout << arr[i] << " ";
		cout << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

