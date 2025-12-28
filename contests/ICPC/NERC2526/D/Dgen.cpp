#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}
void die(string S){puts(S.c_str());exit(0);}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 
#define urd(a,b) uniform_real_distribution<double>(a, b)(rng)

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n = uid(2,2); cout << n << "\n";
	for(int i = 0; i < n; i++){
		int k = uid(1,1);
		int l = uid(1,5);
		int sum=0; vector<int> w(k);
		for(auto& e : w) e = uid(1,5), sum += e;
		int r = uid(l+sum, l+sum+10);
		assert(l+sum<=r);
		cout << k << " " << l << " " << r << " " << w << "\n";
	}
}

