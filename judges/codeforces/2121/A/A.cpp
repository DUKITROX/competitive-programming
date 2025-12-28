#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,s; cin >> n >> s; vector<int> arr(n); cin >> arr;
	if(s <= *min_element(arr.begin(), arr.end()))
		cout << *max_element(arr.begin(), arr.end()) - s << "\n";
	else if(s >= *max_element(arr.begin(), arr.end()))
		cout << s - *min_element(arr.begin(), arr.end()) << "\n";
	else
		cout << *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end()) + min(s - *min_element(arr.begin(), arr.end()), *max_element(arr.begin(), arr.end()) - s) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

