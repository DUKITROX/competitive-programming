#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr, int n, int k, int m){
	set<int> s;
	if(m == 0) return true;
	int cont = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] < m) s.insert(arr[i]);
		if(s.size() > m-1){
			cont++;
			s.clear();
		}
	}
	return (cont >= k);
}

void solve(){
	int n,k; cin >> n >> k;
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	int l = 0, r = n+10, ans = 0;
	
	while(l <= r){
		int m = (l+r)/2;
		if(check(arr, n, k, m)){
			ans = m;
			l = m+1;
		}else{
			r = m-1;
		}
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
