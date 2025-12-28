#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,k; cin >> n >> k;
	string s; cin >> s;
	int sol = 0, cont = 0, un=0;

	for(int i = 0; i < n; i++){
		if(s[i] == '0') cont++;
		else cont = 0,un=1;
		if(cont > k || !un) sol++;
	}
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

