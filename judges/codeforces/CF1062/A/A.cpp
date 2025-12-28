#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n; cin >> n;
	vector<int> arr(n); cin >> arr;
	int sol = 0, cont = 1;
	for(int i = 1; i < n; i++){
		if(i && arr[i-1]+1 == arr[i]) cont++;
		else{
			if(i == arr[i-1]) cont++;
			ckmax(sol,cont-2);
			cont = 1;
		}
	}
	if(arr.back() == 1000 || n==arr.back()) cont++;
	ckmax(sol,cont-2);
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

