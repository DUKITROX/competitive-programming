#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m; cin >> n >> m;
	int cont = 0, res = 0;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		cont += s.length();
		if(cont <= m) res++;
	}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
