#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,m; cin >> n >> m;
	vector<int> a(n),b(m),apur(m,-1);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	int j = m-1;
	for(int i = n-1; i >= 0 && j >= 0; i--)
		if(a[i] >= b[j]) apur[j--] = i;

	int sol = 1e9+7, i = 0; j = 0;
	if(apur[0] >= 0) sol = 0;
	if(m==1||(m>1&&apur[1] >= 0)) sol = min(sol,b[0]);

	while(i < n && j < m){
		if(a[i++] >= b[j]){
			if(j < m-2 && apur[j+2] >= i) sol = min(sol, b[j+1]);
			else if(j == m-2) sol = min(sol, b[j+1]);
			else if(j == m-1) sol = 0;
			j++;
		}
	}
	cout << (sol==1e9+7?-1:sol) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}
