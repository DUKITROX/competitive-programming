#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n = 200000; cout << n << "\n";
	vector<int> arb(n);
	for(int i = 1; i < n; i++) arb[i] = uid(0,i-1), cout << i+1 << " " << arb[i]+1 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "1\n"; solve();
}

