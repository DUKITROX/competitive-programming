#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,k; cin >> n >> m >> k;
	vector<bool> se (n);
	vector<int> arr(m),q(k); for(int i = 0; i< m; i++) cin >> arr[i];
	set<int> mon;
	for(int i = 0; i < k; i++) {cin >> q[i];mon.insert(q[i]);}
	string s="";
	for(int i = 0; i < m; i++){
		if(k==n) s+="1";
		else if(k == n-1 && !mon.count(arr[i])){
			s+="1";
		}else s+="0";
	}
	cout << s << "\n";

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
