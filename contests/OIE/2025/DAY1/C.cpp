#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; while(tt--){
		int n,k,sum=0,cont=0,cant; cin >> n >> k;
		vector<int> arr(n); for(int i = 0; i < n; i++){
			cin >> arr[i]; sum += arr[i];
			cont += arr[i]/k;
			arr[i] %= k;
		}
		cant = k*cont;
		sort(arr.begin(), arr.end());
		vector<int> peak(n);
		int M = *max_element(arr.begin(), arr.end());

		for(int i = 0; i < n; i++){
			int m = min({M-arr[i], cont, cant});
			arr[i] += m; cant -= m;
			peak[i] = cont-m;
		}
		for(int i = 0; i < n; i++) cout << peak[i] << " ";
		cout << endl;
		int XIANG = M, h = 0;
		for(int i = 0; i < n && cant; i++){
			int a = (peak[i] - h)*(n-i);
			h = max(h, peak[i]);

			int b = cant/(n-i) + (cant%(n-i) > 0 && cant <= a) + h;
			XIANG = max(XIANG, b);
			
			cant = max(0LL, cant-a);
		}
		cout << XIANG*n - sum << "\n";
    }
}
