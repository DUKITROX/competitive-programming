#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

void solve(){
	int n = uid(1, 5), L = uid(5, 20);
	cout << n << " " << L << "\n";
	for(int i = 0; i < n; i++){
		cout << uid(1, 15) << " " << uid(1, 50) << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}

