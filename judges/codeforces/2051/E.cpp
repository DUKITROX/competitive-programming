#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k; cin >> n >> k;
	vector<int> a(n),b(n); 
	vector<pair<int,int>> arr(n<<1);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++){
		arr[i<<1].first = a[i]; 
		arr[i<<1].second = i;

		arr[(i<<1)+1].first = b[i]; 
		arr[(i<<1)+1].second = i;
	}
	sort(arr.begin(),arr.end());

	long long sol = 0, active = n;
	set<int> s;

	for(int i = 0; i < n<<1; i++){
		
	}

	cout << sol << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
