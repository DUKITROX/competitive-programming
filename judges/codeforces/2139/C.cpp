#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int64_t k,x,c; cin >> k >> x; c = 1LL<<k;
	if(x == 0 || x == c*2) cout << "-1\n";
	else{
		int64_t l = c*2 - x; vector<int64_t> sol;
		while(x!=c){
			if (x > l) sol.push_back(2),x-=l,l*=2;
			else sol.push_back(1),l-=x,x*=2;
		}
		reverse(sol.begin(), sol.end());
		cout << sol.size() << "\n" << sol << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

