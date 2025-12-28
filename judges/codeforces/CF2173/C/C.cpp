#include <bits/stdc++.h>
using namespace std;

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,k; cin >> n >> k;
	vector<int> a(n); cin >> a;
	set<int> act, av;
	for(int i = 0; i < n; i++){act.insert(a[i]); av.insert(a[i]);}
	vector<int> sol;
	while(!act.empty()){
		int m = *act.begin();
		sol.push_back(m);

		while(m <= k){
			if(!av.count(m)){
				cout << "-1\n";
				return;
			}
			act.erase(m);
			m += sol.back();
		}
	}
	cout << sol.size() << "\n" << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

