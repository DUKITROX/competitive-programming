#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,q; cin >> n >> q;
	vector<int> arr(n), perm(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i]; arr[i]--;
		perm[arr[i]] = i;
	}
	for(int i = 0; i < q; i++){
		int l,r,k; cin >> l >> r >> k; l--; r--; k--;
		if(perm[k] < l || r < perm[k]){cout << "-1 "; continue;}
		int cont = 0, iz = 0, der = 0;
		int L=0,G=0;
		while(l<=r){
			int m = (l+r)>>1;
			if(m == perm[k]) break;
			else if(perm[k] < m) { // left
				der++;
				r = m-1;
				if(arr[m] < k){
					L++;
					cont++;
				}
			}else{ // right
				iz++;
				l = m+1;
				if(arr[m] > k){
					G++;
					cont++;
				}
			}
		}
		if(iz > k || k + der >= n) {
			cout << "-1 ";
		}else{
			int a = min(L,G);
			int b = max(L,G)-a;
			cout << 2*a + b*2 << " ";
		}
	}
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

