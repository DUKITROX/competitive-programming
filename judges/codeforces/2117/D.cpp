#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	int y = ((2*arr[0]-arr[1])%(n+1)==0 ? (2*arr[0]-arr[1])/(n+1) : -1);
	int x = (y != -1 && arr[0] - n*y >= 0 ? arr[0]-n*y : -1);
	for(int i = 2; i < n; i++){
		if((i+1)*x + (n-i)*y != arr[i]) x = y = -1;
	}
	if(x==-1) cout << "NO\n";
	else cout << "YES\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

