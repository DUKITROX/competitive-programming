#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,k; cin >> n >> k;
	int sol = 0;
	set<pair<int,int>> s; int cont = 0, jojo;
	for(int i = 0; (1<<i) <= n; jojo = ++i){
		if((1<<i) & n) cont++;
		else s.insert({cont, i}), cont=0;
	} if(cont)s.insert({cont, jojo});

	set<int> s2;
	while(!s.empty() && k--){
		sol += (*s.begin()).first;
		s2.insert((*s.begin()).second);
		s.erase(s.begin());
	}

	if(k <= 0) {
		cout << sol << "\n";
		return;
	}

}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

