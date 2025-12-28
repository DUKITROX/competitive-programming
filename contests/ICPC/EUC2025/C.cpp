#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n, k; cin >> n >> k;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int cont = 0, l = 0, r = n-1, sum = 0, last = n-1;
	int llevo = n;
	while(l < r){
		while(l < r && arr[l] + arr[r] >= k) r--;
		if(l < r){
			while(l < last && (arr[last] == -1 || last == r)) last--;
			if(l < last && r != last){
				llevo -= 3;
				cont++;
				arr[l] = arr[r] = arr[last] = -1;
				while(l < n && arr[l] == -1) l++;
				while(r >= 0 && arr[r] == -1) r--;
			}else break;
		}
	}
	int puesto = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] != -1){
			puesto = 1;
			if(llevo > 1 && arr[i] < k){
				cont++;
				llevo -= 2;
			}else if (llevo > 0){
				cont++;
				llevo--;
			}
		}
	}
	cout << cont-1 << "\n";
}

signed main(){
	int tt; cin >> tt; while(tt--) solve();
}
