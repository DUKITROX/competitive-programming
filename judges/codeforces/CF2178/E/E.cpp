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
	int L = 1, R = n, sum = 0;
	cout << "? " << L << " " << R << endl; cin >> sum;
	while(L < R){
		int l = L, r = R, m, s = -1, ans;
		while(l <= r){
			int m = (l+r)/2;
			cout << "? " << L << " " << m << endl;
			cin >> s;
			if(m==L){cout << "! " << s << endl;return;}
			if(s <= sum/2){
				ans = m;
				l = m+1;
			}else{
				r = m-1;
			}
		}
		sum >>= 1;
		if(R-ans > ans-L+1) R = ans;
		else L = ans+1;
	}
	cout << "! " << sum << endl;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

