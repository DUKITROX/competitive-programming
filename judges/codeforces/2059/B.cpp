#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n,k; cin >> n >> k; vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];

	int res = -1;
	for(int i = 1; i < n-k+2; i++) if(arr[i] != 1) res = 1;
	if(res != 1){
		if(arr[1] != 1) res = 1;
		else if(n >= 3 && n-k >= 1 && arr[2] != 2) res = 2;
		else if(n >= 4 && arr[3] != 2) res = 2;
		else if(n>= 4 && n-k >= 1) res = 3;
		else res = k/2 + 1;
	}

	cout << res <<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
