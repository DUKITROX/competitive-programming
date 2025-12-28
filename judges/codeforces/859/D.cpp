#include <bits/stdc++.h>
using namespace std;

long long arr[200000];

void solve(){
	int n,q;
	cin >> n >> q >> arr[0];
	arr[0] %= 2;
	for(int i = 1; i < n; i++) {
		cin >> arr[i];
		arr[i] += arr[i-1]%2;
	}
	int l,r,k;
	for(int i = 0; i < q; i++){
		cin >> l >> r >> k;
		long long sum = (r-l+1)*k%2;
		if(l > 1) sum += arr[l-2];
		sum += arr[n-1]%2;
		sum -=
		sum %=2;
		if(sum) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}

