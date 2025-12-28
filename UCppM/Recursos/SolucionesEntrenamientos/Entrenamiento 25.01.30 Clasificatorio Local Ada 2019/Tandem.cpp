#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int n,P; while(cin >> n >> P && (n || P)){
		vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
		sort(arr.begin(), arr.end());
		int res = 0;
		for(int i = 0; i < n; i++){
			int cant = upper_bound(arr.begin(),arr.end(),P-arr[i])-arr.begin();
			cant -= i+1;
			if(cant < 0) break;
			res += cant;
		}
		cout << res << "\n";
	}
}
