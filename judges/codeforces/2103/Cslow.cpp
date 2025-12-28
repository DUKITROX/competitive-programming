#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,K; cin >> n >> K;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	int ok = 0;
	for(int i = 0; i < n-2; i++){
		for(int j = i+1; j < n-1; j++){
			int cont = 0, acum = 0;
			for(int k = 0; k <= i; k++){
				acum += (arr[k] <= K ? 1 : -1);
			}
			if(acum >= 0) cont++;
			acum = 0;
			for(int k = i+1; k <= j; k++){
				acum += (arr[k] <= K ? 1 : -1);
			}
			if(acum >= 0) cont++;
			acum = 0;
			for(int k = j+1; k < n; k++){
				acum += (arr[k] <= K ? 1 : -1);
			}
			if(acum >= 0) cont++;
			if(cont >= 2) ok = 1;
			cont = 0;
		}
	}
	cout << (ok?"YES":"NO") << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

