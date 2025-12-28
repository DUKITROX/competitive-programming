#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}
void die(string S){puts(S.c_str());exit(0);}

void solve(){
	string s; int cont = 0; cin >> s;
	int n = s.size();
	if(s[0]=='u'&&++cont)s[0]='s';
	if(s[n-1]=='u'&&++cont)s[n-1]='s';
	int act=0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'u') act++;
		else cont += act/2, act=0;
	}
	cout << cont << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

