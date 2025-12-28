#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t
int mod = 1e9+7;

void solve(){
	string s; cin >> s;
	int sol = 0, cad = 1, acum = 0;
	for(int i = 0; i < s.length(); i++){
		char c = s[i];
		if(c == '0'){
			sol += acum; sol %= mod;
		}else if(c == '1'){
			acum += cad; acum %= mod;
		}else if(c == '?'){
			sol += acum + sol; sol %= mod;
			acum <<= 1; acum %= mod;
			acum += cad; acum %= mod;
			cad <<= 1; cad %= mod;
		}
	}
	cout << (sol%mod) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

