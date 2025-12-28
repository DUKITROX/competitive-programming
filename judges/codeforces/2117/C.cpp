#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n;
	int cont = 0;
	vector<set<int>> s(2); int act=0,prev=1;
	set<int> aux;
	int goal=0,c=0;

	for(int i = 0; i < n; i++){
		int a; cin >> a;
		s[act].insert(a);
		if(s[prev].count(a)) aux.insert(a);
		if(s[prev].size()==aux.size()){
			cont++;
			swap(prev,act);
			s[act].clear();
			aux.clear();
		}
	}

	cout << cont << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

