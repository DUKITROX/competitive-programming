#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,d; cin >> n >> d;
	vector<int> arr(n); cin >> arr;
	if(d == 0){
		int c = 0, d = 0;
		for(auto e : arr) {
			if(e%2==0) d++;
			if(e%5==0) c++;
		}
		if(c && d) cout << n << "\n" << arr << "\n";
		else cout << "-1\n";
	}else
		cout << "NO\n";
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

