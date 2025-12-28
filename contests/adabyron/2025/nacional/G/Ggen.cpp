#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

void solve(){
	int n = uid(1,300), m = uid(1,300);
	cout << n << endl; for(int i = 0; i < n; i++) cout << uid(1,3000) << " "; cout << endl;
	cout << m << endl; for(int i = 0; i < m; i++) cout << uid(1,3000) << " "; cout << endl;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

