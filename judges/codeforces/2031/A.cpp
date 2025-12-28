#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n; int res = 0;
	map<int,int> m;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		res = max(res, ++m[a]);
	}
	cout << n-res << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
