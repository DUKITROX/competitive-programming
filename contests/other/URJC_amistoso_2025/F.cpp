#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int a,b; cin >> a >> b;
	if(!a && !b) cout << "DERECHA\n";
	else{
		if((a+b)%2) cout << "IZQUIERDA\n";
		else cout << "DERECHA\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

