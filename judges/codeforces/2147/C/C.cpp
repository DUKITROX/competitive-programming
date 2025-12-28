#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n; cin >> n;
	string s; cin >> s; 
	if(s[0] == '0') s[0] = '2';
	if(s[n-1] == '0') s[n-1] = '2';
	for(int i = 1; i < n-1; i++){
		if(s[i] == '0'){
			if(s[i-1] == '0' || s[i-1] == '2' || s[i+1] == '0' || s[i+1] == '2') s[i] = '2';
		}
	}
	int cant = 0;
	bool pos = true;
	//cout << s << endl;
	for(int i = 1; i < n-1; i++){
		if(s[i] == '1' && s[i-1] == '1' && cant%2 == 1)  pos = false;
		if(s[i] == '0'){
			cant++;
			if(s[i+2] == '2' || s[i-2] == '2'){
				s[i] = '2';
				cant = 0;
			}
		}
	}
	if(cant%2 == 1) pos = false;
	cout << (pos ? "YES" : "NO") << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

