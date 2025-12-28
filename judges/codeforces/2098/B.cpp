#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

#define sort(x) sort(x.begin(), x.end())

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T> istream& operator>>(istream& is, vector<T>& v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}

void solve(){
	int n,k; cin >> n >> k;
	vector<int> arr(n); cin >> arr; sort(arr);
	cout << arr[n/2+(k+n&1)/2] - arr[n/2-(k+n&1)/2-(n&1==0)] + 1 << "\n";
}

void solve2(){
	int n,k; cin >> n >> k;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr);
	int r = n/2 + (k + (n%2==1))/2, l = n/2 - (n%2 == 0) - (k + (n%2==1))/2;
	cout << arr[r] - arr[l] + 1 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve2();
}

