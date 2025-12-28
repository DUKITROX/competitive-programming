#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n; cin >> n;
	int M = 0,x;
	vector<string> s(n);
	for(int i = 0; i < n; i++) s[i] = to_string(i+1);
	vector<int> pos(n+1);
	for(int i = 0; i < n; i++){
		cout << "? " << to_string(i+1) << " " << n << " " << s << endl;
		int a; cin >> a;
		if(a == -1) exit(0);
		pos[i+1] = a;
		if(ckmax(M,a)){
			x = i+1;
		}
	}

	int c = M;
	set<int> r;
	vector<int> sol(c); sol[0] = x;
	for(int i = 1; i <= n; i++){
		if(i == x) continue;
		cout << "? " << to_string(x) << " " << n - 1 - r.size();
		for(int j = 0; j < n; j++) if(j+1 != i && !r.count(j+1)) cout << " " << j+1;
		cout << endl;

		int a; cin >> a;
		if(a == -1) exit(0);
		if(a!=c) {
			sol[c-pos[i]] = i;
		} else r.insert(i);
	}

	cout << "! " << c << " " << sol << endl;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

