#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int n; while(cin >> n && n){
		vector<pair<int,int>> arr;
		for(int i = 0; i < n; i++){
			int x,y; cin >> x >> y;
			arr.push_back({x-y,1});
			arr.push_back({x+y+1,-1});
		}
		sort(arr.begin(),arr.end());
		int res = 0, cont = 0;
		for(int i = 0; i < 2*n; i++){
			cont += arr[i].second;
			res = max(res, cont);
		}
		cout << res << "\n";
	}
}
