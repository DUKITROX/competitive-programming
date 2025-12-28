#include <bits/stdc++.h>
using namespace std;

void solve(){
	 int n,k; cin >> n >> k;
	 vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	 sort(arr.begin(),arr.end(),greater<int>());
	 int sum = 0;
	 for(int i = 0; i < n; i++){
	 	if(sum + arr[i] > k) break;
		sum += arr[i];
	 }
	 cout << k - sum << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
