#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	 int n; cin >> n;
	 vector<int> arr(n); for(int i = 0; i < n-2; i++) cin >> arr[i];
	 bool ok = true;
	 for(int i = 0; i < n-4; i++){
	 	if(arr[i] == 1 && arr[i+1] == 0 && arr[i+2] == 1) ok = false;
	 }
	 cout << (ok?"YES":"NO") << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
