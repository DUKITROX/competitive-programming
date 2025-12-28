#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	long long imp = 0, par = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a%2)imp+=a;
		else par+=a;
	}
	if(par > imp) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}

