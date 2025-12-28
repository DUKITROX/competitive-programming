#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

void solve(){
	int f = uid(3, 50), c = uid(3,50);
	cout << f << " " << c ;
	for(int i = 0; i < f; i++){
		for(int j = 0; j < c; j++){
			int a = uid(0,1);
			if(a) cout << ".";
			else cout << "#";
		}
		cout << endl;
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "1\n";
	solve();
}

