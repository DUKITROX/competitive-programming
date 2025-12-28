#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,x; cin >> n >> x;
	int f=-1,s=-1;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		if(a==1&&f==-1) f = s = i;
		else if(a == 1) s = i;
	}
	cout << (s-f<x||f==-1?"YES":"NO") << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

