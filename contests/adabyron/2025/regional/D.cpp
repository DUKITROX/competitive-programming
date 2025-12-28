#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int getN(char c){
	if(c <= '9') return c - '0';
	else return 10 + c - 'A';
}
char  getC(int n){
	if(n <= 9) return '0' + n;
	else return 'A' + n - 10;
}

void solve(){
	string s, sol=""; cin >> s;
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.length()/5; i+=5){
		int a = 0, mult = 1;
		for(int j = 0; j < 5; j++){
			a += getN(s[i+j])*mult;
			mult <<= 4;
		}
		for(int i = 0; i < 4; i++){
			sol += getC(a%32);
			a /= 32;
		}
	}
	reverse(sol.begin(), sol.end());
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto start = chrono::high_resolution_clock::now();
	int tt; cin >> tt; while(tt--) solve();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	#ifndef LOCAL
	cout << setprecision(3) << fixed << "Time: " << elapsed_seconds.count() << " seconds\n";
	#endif
}

