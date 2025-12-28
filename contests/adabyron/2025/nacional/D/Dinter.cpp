#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

#define int int64_t

void solve(){
	int n = uid(1,100000000); int sol = uid(1,n); int SOL = sol;
	cout << n << endl;
	string s; int a; while(cin >> s >> a && s != "=>"){
		if(a <= sol)	{
			cout << "SI" << endl;
			sol <<= 1;
		}else{
			cout << "NO" << endl;
		}
	}
	if(a == SOL)  {
		cout << "OK" << endl;
		exit(0);
	}else{
		cout << "MAL" << endl;
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
	cout << "0" << endl;
}

