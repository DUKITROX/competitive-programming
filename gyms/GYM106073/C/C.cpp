#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void show(int m){
	for(int i = 20; i >= 0; i--){
		cout << (m&(1<<i)?1:0);
	}
	cout << endl;
}
void solve(){
	int n, mask=0; cin >> n;
	for(int i = n; i >= 0; i--){
		int a; cin >> a;
		mask |= (a<<i);
	}
	int cont = 0;
	while(mask > 1){
		if(mask&1) mask ^= ((mask<<1) + 1);
		else mask >>= 1;
		cont++;
	}
	cout << cont << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

