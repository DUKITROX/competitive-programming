#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

void solve(){
	int64_t n = uid(1,10000), k = uid(1e2, 100000000);
	cout << n << " " << k << endl;
	assert(k > 0 && n > 0);
	string s;
	for(int i = 0; i < n; i++)
		s += to_string(uid(0,1));
	cout << s << endl;
	for(int i = 0; i < n; i++){
		if(s[i] == '0') cout << 0 << " ";
		else cout << uid(1,1e6) << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "1\n";
	solve();
}

