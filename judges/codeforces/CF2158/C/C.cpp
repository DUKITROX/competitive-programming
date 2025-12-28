#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n,k; cin >> n >> k;
	vector<int>a(n),b(n); cin >> a >> b;

	if(k%2==0){
		int gMax = a[0];
		int lMax = a[0];
		for(int i = 1; i < n; i++){
			lMax = max(lMax+a[i], a[i]);
			ckmax(gMax,lMax);
		}
		cout << gMax << "\n";
	}else{
		int lMax1 = a[0];
		int lMax2 = a[0] + b[0];
		int gMax = max(lMax1, lMax2);
		for(int i = 1; i < n; i++){
			lMax2 = max({lMax2 + a[i], lMax1 + a[i] + b[i], a[i] + b[i]});
			lMax1 = max(lMax1 + a[i], a[i]);
			gMax = max({gMax, lMax1, lMax2});
		}
		cout << gMax << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

