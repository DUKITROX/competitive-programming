#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n; cin >> n;
	vector<int> arr(n); cin >> arr;
	sort(arr.begin(), arr.end());
	int cont = 0, sum = 0, s2=0;
	for(auto e : arr) {
		sum += e;
		if(e>1) s2+= e-1;
	}

	int sol = n; sol -= s2;
	if(sol <= 1) cout << arr.end() - upper_bound(arr.begin(), arr.end(), 0) << "\n";
	else  cout << arr.end() - upper_bound(arr.begin(), arr.end(), 0) - sol + 1 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

