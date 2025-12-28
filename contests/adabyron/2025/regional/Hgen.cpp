#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 1e2;
	string s = "(()())";
	for(int i = 0; i < n; i++){
		s += "(())";
	}
	for(int i = 0; i < n/2; i++) 
		s+="()";
	cout << s << "\n";
}

