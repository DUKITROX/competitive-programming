#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	multiset<int> s;
	string sr; cin >> sr;
	for(int i = 0; i < 10; i++){s.insert((sr[i]-'0'));}
	for(int i = 9; i >= 0; i--){
		auto it = s.lower_bound(i);
		cout << *it;
		s.erase(it);
	}
	cout << endl;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

