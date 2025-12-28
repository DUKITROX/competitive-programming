#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}
void die(string S){puts(S.c_str());exit(0);}

#define int int64_t

void solve(){
	int n; cin >> n;
	vector<int> a(n+1);
	int S = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		S += a[i];
	}

	int best = -S + a[1];
	int sumPos = 0; 
	for (int U = 2; U <= n; U++) {
		int cand = -S + a[U] + 2LL * a[1] + 2LL * sumPos;
		best = max(best, cand);
		if (a[U] > 0) sumPos += a[U];
	}

	cout << best << "\n";
	return;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

