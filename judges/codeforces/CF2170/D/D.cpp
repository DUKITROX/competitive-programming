#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,q; cin >> n >> q;
	string s; cin >> s;

	int sum=0, l = 0, r = 0, f = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'X')  sum += 10;
		else if(s[i] == 'V') sum += 5;
		else if(s[i] == 'I'){
			if(i < n-1 && s[i+1] != 'I') sum--;
			else sum++;
		}else{
			if(i && s[i-1] == 'I') l++;
			else if(i < n-1 && s[i+1] != 'I') r++;
			f++;
		}
	}

	for(int i = 0; i < q; i++){
		int cX, cV, cI; cin >> cX >> cV >> cI;

		
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

