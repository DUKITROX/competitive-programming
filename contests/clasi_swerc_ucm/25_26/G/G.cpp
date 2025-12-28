#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n; cin >> n;
	vector<string> m1(n),m2(n); cin >> m1 >> m2;
	int SOL=0,sol=0;
	for(int k = 0; k < (1<<(n+1)); k++){
		sol = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){

			}
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

