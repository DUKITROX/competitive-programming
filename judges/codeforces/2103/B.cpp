#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	int cont = 1; for(int i = 1; i < n; i++){
		if(s[i] != s[i-1]) cont++;
	}
	if(cont == 1){
		if(s[0] == '0') cout << n << "\n";
		else cout << n+1 << "\n";
	}else if(cont == 2){
	 	cout << n+1 << "\n";
	}else if(cont == 3){
		cout << n+1 <<"\n";
	}else{
		if(s[0] == '0') cout << n+cont-3 << "\n";
		else  cout << n+cont-2 << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

