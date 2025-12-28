#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k; cin >> n >> k;
	string s; cin >> s;
	vector<int> vec(n); for(int i = 0; i < n; i++) cin >> vec[i];

	auto check = [&](int m)->bool{
		int count = 0, i = 0;
		while(i < n){
			if(vec[i] <= m || s[i] == 'R') i++;
			else{
				while(i < n && ((s[i] == 'R' && vec[i] <= m) || s[i] == 'B'))
					i++;
				count++;
			}
		}
		return count <= k;
	};

	int l = 0, r = 1e9, ans = 1e9;
	while(l <= r){
		int m = ((r-l)>>1)+l;
		if(check(m)) {
			ans = m;
			r = m-1;
		}else
			l = m+1;
	}
	cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t; while(t--) solve();
}
