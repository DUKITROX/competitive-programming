#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define cin fin
#define cout fout

int32_t main(){
	ios::sync_with_stdio(false);

	ifstream fin("input");
	ofstream fout("output");
	
	int n; cin >> n; cout << n << endl;

	fin.close();
	fout.close();
}

