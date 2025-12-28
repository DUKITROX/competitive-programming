#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	multiset<pair<int,int>> ms;
	map<int,int> frec;
	int n; cin >> n; vector<int> arr(n); cin >> arr;
	for(int i = 0; i < n; i++) frec[arr[i]]++;
	for(auto [f,s] : frec) ms.insert({s,f});
	int a=0,b=0,t=0;
	while(ms.size() > 1){
		auto [f,ind] = *ms.begin();
		if(!t){

		}else{

		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

