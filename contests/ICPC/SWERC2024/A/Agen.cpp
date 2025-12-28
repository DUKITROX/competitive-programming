#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 
#define urd(a,b) uniform_real_distribution<double>(a, b)(rng)

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n = uid(3,100), q = uid(1,10); cout << n << " " << q << endl;
	for(int i = 0; i < n; i++) cout << uid(-50,50) << " "; cout << endl;
	for(int i = 0; i < n; i++){
		if(uid(0,10) < 4) cout << "STRENGTH " << uid(-50,50) << endl;
		else{
			int l = uid(1, n); int r = uid(l,n);
			cout << "ASSESS " << l << " " << r << endl;
		}
	}
}

