#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n; string s; cin >> n >> s;
	set<char> se;
	int can = 0;

	for(int i = 0; i < n-1; i++) {
		if(i && se.count(s[i])) can = 1;
		se.insert(s[i]);
	}

	se.clear();
	for(int i = n-1; i >= 1; i--) {
		if(i < n-1 && se.count(s[i])) can = 1;
		se.insert(s[i]);
	}
	if(can) cout << "YES\n";
	else cout << "NO\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

