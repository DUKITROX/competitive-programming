#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

void solve(){
	int n = uid(1,10); cout << n << "\n";
	int k = uid((int)ceil()(log2(n)));
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt=1;cout << tt << "\n";while(tt--) solve();
}

