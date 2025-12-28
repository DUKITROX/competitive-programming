#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int INF = 1e9+7;

void solve(){
	int n,k; cin >> n >> k;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	set<int> pre,suf;
		
	int acum = 0, ok = 0;
	for(int i = 0; i < n; i++)	
		if((acum += (arr[i] <= k ? 1 : -1)) >= 0)  pre.insert(i);
	acum = 0;
	for(int i = n-1; i >= 0; i--)	
		if((acum += arr[i] <= k) >= (n-i)/2 + (n-i)%2)  suf.insert(i);
	if(!pre.empty() && !suf.empty() && *pre.begin() < *suf.rbegin() - 1) ok = 1;

	acum = 0;
	if(!pre.empty()){
		for(int i = *pre.begin()+1; i < n; i++){
			acum = max(acum + (arr[i] <= k ? 1 : -1), (pre.count(i-1) ? (arr[i] <= k ? 1 : -1 ): -INF));
			if(acum >= 0 && i < n-1) ok = 1;
		}
	}
	acum = 0;
	if(!suf.empty()){
		for(int i = *suf.rbegin()-1; i >= 0; i--){
			acum = max(acum + (arr[i] <= k ? 1 : -1), (suf.count(i+1) ? (arr[i] <= k ? 1 : -1 ) : -INF));
			if(acum >= 0 && i > 0) ok = 1;
		}
	}
	cout << (ok ? "YES" : "NO") << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

