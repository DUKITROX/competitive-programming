#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; while(cin >> n && n){
		int l = 1, r = n, cont = 0, ans = -1;
		while(l <= r){
			int m = 0.666666*(r-l) + l;
			cout << "? " << m << endl;
			string res; cin >> res;
			if(res == "NO"){
				r = m-1;
			}else{
				m <<= 1;
				r <<= 1;
				cont++;
				ans = m;
				l = m+2;
			}
		}
		cout << "=> " << (ans>>cont) << endl;
	}
}

