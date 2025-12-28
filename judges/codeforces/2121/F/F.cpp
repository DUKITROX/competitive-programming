#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

int n,s,x;

int cont(int l, int r, vector<int>& pref){ // [l,r]
	int sum = 0;
	map<int,int> m;
	m[0]++;

	for(int i = l; i <= r; i++){
		int curr_sum = pref[i] - (l > 0 ? pref[l - 1] : 0);
		sum += m[curr_sum - s];
		m[curr_sum]++;
	}
	return sum;
}

void solve(){ 
	cin >> n >> s >> x; vector<int> arr(n), pref(n+1); cin >> arr; arr.push_back(1e9+5);
	for(int i = 0; i <= n; i++) pref[i] = arr[i] + i ? pref[i-1] : 0;

	int sum = 0, res = 0;
	int L = 0, R = 0;
	set<int> quit;

	while(R < n){
		if(arr[R] > x){
			if(L < R){
				sum += cont(L,R-1,pref);
				for(auto e : quit){
					if(L < e){
						res += cont(L, e-1, pref);
						L = e+1;
					}
				}
				if(L < R)
					res += cont(L,R-1, pref);
			}
			L = ++R;
			quit.clear();
		}else{
			if(arr[R] == x) quit.insert(R);
			R++;
		}
	}

	cout << sum << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

