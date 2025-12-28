#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n; cin >> n; 
	map<int,int> m;
	for(int i = 0; i < 2*n; i++){
		int a; cin >> a; m[a]++;
	}
	int sol=0,sac=0,can=0;
	for(auto [f,s] : m){
		if(s%2) sol++,can=1;
		else  sac+=(s-2)/2, sol += 2;
	}
	if(sac%2 && !can) cout << sol - 2 << "\n";
	else cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

