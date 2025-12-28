#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n; cin >> n;
	vector<vector<int>> arr(n,vector<int>(n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> arr[i][j];

	multiset<int> ms; 
	for(int i = 0; i  < n; i++){
		int cont = 0;
		for(int j = n-1; j >= 0; j--){
			if(arr[i][j] == 1) cont++;
			else break;
		}
		ms.insert(cont);
	}
	int res = 1;
	for(auto e : ms){
		if(e >= res)	{
			res++;	
		}
	}
	if(res > n)  cout << n << "\n";
	else cout << res <<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
