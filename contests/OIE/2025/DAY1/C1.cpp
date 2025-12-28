#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,k,sum=0; cin >> n >> k;
	vector<int> arr(n); for(int i = 0; i < n; i++){cin >> arr[i]; sum += arr[i];}
	if(k < n-1){
		cout << (sum/n + (sum%n?1:0))*n - sum << "\n";
	}else{
		
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

