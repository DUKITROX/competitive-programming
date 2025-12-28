#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n, pos = 0; cin >> n;
	map<int,int> m;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		m[a]++;
	}
	int prev = -1;
	for(auto e : m){
		if(e.second >= 4) pos = 1;
		if(prev != -1){
			if(e.first-1 == prev){
				if(e.second >= 2) pos = 1;
				else prev = e.first;
			}else{
				if(e.second >= 2) prev = e.first;
				else prev = -1;
			}
		}else if(e.second >= 2) prev = e.first;
	}
	cout << (pos?"YES":"NO") << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

