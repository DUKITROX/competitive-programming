#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,m; cin >> n >> m;
	priority_queue<int> a,b; 
	for(int i = 0; i < n; i++){int x; cin >> x; a.push(x);}
	for(int i = 0; i < m; i++){int x; cin >> x; b.push(x);}
	int win=1;
	while(!a.empty() && !b.empty()){
		int A = a.top(); a.pop();
		int B = b.top(); b.pop();
		if(win){ //alice
			a.push(A);
			if(A < B)
				b.push(B-A);
		}else{ //bob
			b.push(B);
			if(B < A)
				a.push(A-B);
		}
		win^=1;
	}
	cout << (!win?"Alice":"Bob") << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

