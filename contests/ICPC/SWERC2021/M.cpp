#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m; cin >> n >> m;
	int R=0,W=0;
	for(int i = 0; i < m; i++){
		int r,w; cin >> r >> w;
		R = max(R,r);
		W = max(W,w);
	}
	if(R+W>n) cout << "IMPOSSIBLE\n";
	else{
		for(int i = 0;i  < R; i++) cout << "R";
		for(int i  = 0; i < n-R; i++) cout << "W";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
