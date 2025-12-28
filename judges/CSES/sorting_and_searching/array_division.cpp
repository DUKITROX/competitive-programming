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
	
	auto check = [&](int m)->bool{
		int cont = 1, sum = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] > m) return false;
			sum += arr[i];
			if(sum > m) {
				sum = arr[i];
				cont++;
			}
		}
		return cont <= k && sum <= m;
	};

	int l = 0, r = 1e18, sol = 1e18;
	while(l<=r){
		int m = l + (r-l)/2;
		if(check(m)){
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

