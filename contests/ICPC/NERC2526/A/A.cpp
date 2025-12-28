#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n,m; cin >> n >> m;
	map<char,int> f;
	vector<map<char,int>> g(n);
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		for(auto e : arr[i]) 
			f[e]++, g[i][e]++;
	}
	for(int i = 0; i < n; i++){
		int sol = 0;
		for(auto [letra,cant] : g[i]){
			int avb = f[letra] - cant;
			if(avb <= 0) {
				cout << "-1 ";
				goto megaB;
			}
			ckmax(sol, cant/avb + (cant%avb!=0));
			//cout << letra << " : " << avb << " " << cant << "\n";
		}
		cout << (sol > m ? -1 : m-sol) << " ";
		megaB:;
	}
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

