#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,k; cin >> n >> k;
	int64_t sum = 0;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
	arr[max_element(arr.begin(), arr.end()) - arr.begin()]--;
	if(*max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end()) > k) cout << "Jerry\n";
	else{
		cout << (sum%2?"Tom":"Jerry") << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

