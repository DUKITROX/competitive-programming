#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	long long left=0,right=0;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		if(i%2) left+=a;
		else right+=a;
	}
	cout << (right%((n+1)/2) == 0 && left%(n/2) == 0 &&  left/(n/2) == right/((n+1)/2)? "YES":"NO") << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
