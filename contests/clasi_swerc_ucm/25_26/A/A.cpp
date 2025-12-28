#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

const int N = 1e6+100LL, M = 1e12+100LL;
bitset<N> isP; 
vector<int> alm;

void solve(){
	int a,b; cin >> a >> b; 
	cout << upper_bound(alm.begin(), alm.end(), b) - lower_bound(alm.begin(), alm.end(), a) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	isP.set(); isP[0] = isP[1] = 0;
	for(int i = 2; i < N; i++){
		if(isP[i]){
			int j = i*i; while(j < M) {alm.push_back(j); j*=i;}
			for(j = 2*i; j < N; j+=i) isP[j] = 0;
		}
	}
	sort(alm.begin(), alm.end());
	int tt; cin >> tt; while(tt--) solve();
}

