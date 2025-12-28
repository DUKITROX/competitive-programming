#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n,k; cin >> n >> k;
	vector<int> arr(n); cin >> arr;

	int l = 0, r = 1e18, sol;
	while(l <= r){
		int m = (l+r)/2;

		__int128 cont = 0;
		for(int i = 0; i < n; i++) cont += m/arr[i];

		if(cont >= k){
			sol = m;
			r = m-1;
		}else{
			l = m+1;
		}
	}
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

