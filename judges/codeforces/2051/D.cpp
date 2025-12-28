#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
	ll n,x,y,sum=0; cin >> n >> x >> y;
	vector<ll> arr(n);

	ll L = sum-y, R = sum-x;
	sort(arr.begin(),arr.end());
		
	ll res = 0;
	for(int i = 0; i < n; i++){
		res += upper_bound(arr.begin(),arr.end(),R-arr[i]) - lower_bound(arr.begin(),arr.end(),L-arr[i]);
		if(L-arr[i]<=arr[i]&&arr[i]<=R-arr[i]) res--;
	}
	cout << res/2 << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
