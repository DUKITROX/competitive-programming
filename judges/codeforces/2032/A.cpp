#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,u=0,o=0; cin >> n;for(int i = 0; i < 2*n; i++){int a; cin >> a; if(a)u++;else o++;}
	cout <<n- u/2-o/2 << " " << min(u,o) << "\n";
}

int main(){
	int t; cin >> t; while(t--) solve();
}
