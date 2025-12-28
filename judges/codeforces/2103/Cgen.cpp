#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

void solve(){
	int n = uid(100,200);
	int k = uid(1,200);
	cout << n << " " << k << endl;
	for(int i = 0; i < n; i++){
		cout << uid(1, 150) << " ";
	}
	cout << endl;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "1\n"; solve();
}

