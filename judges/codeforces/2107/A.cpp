#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n;
	vector<int> arr(n); int same = -1;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	same = max_element(arr.begin(), arr.end()) - arr.begin();
	int g = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] != arr[same]) g = gcd(g, arr[i]);
	}
	if(g == arr[same] || !g) cout << "NO\n";
	else{
		cout << "YES\n";
		for(int i = 0; i < n; i++){
			cout << (arr[i] == arr[same]?1:2) << " \n"[i==n-1];
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

