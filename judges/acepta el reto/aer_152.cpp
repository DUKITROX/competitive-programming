#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; while(cin >> n && n){
		map<int,int> frec;
		for(int i = 0; i < n; i++){
			int a; cin >> a;
			assert(a >= 0);
			frec[a]++;
		}
		int cant=0,sol=0;
		for(auto& f : frec){
			if(ckmax(cant,f.second))
				sol = f.first;
		}
		cout << sol << endl;
	}
}

