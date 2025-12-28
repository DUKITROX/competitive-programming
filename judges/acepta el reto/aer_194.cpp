#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	string s; cin >> s;
	int sol = 0, cont = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'X'){
			if(i >= 2 && s[i-2] == '.' || i >= 1 && s[i-1] == '.') cont++;
			else {
				sol += cont/3 + cont%3>0;
				cont = 0;
			}
		}else cont++;
	}
	cout << sol + cont/3 + (cont%3 > 0)<< "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

