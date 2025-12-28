#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
	int tt; cin >> tt; while(tt--){
		int n; cin >> n; vector<int> arr(2*n);
		int sum = 0;
		for(int i = 0; i < 2*n; i++){
			cin >> arr[i];
		} sort(arr.begin(), arr.end(), greater<int>());

		for(int i = 0; i < n; i++) {sum += arr[i]; sum -= arr[i+n];}

		cout << sum << " ";
		for(int i = 0; i < n; i++){
			cout << arr[i] << " " << arr[i+n] << " \n"[i == n-1];
		}
	}
}
