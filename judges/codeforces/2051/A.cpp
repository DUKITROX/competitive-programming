#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> a(n),b(n);
	for(int i = 0;  i < n; i++) cin >> a[i];
	for(int i = 0;  i < n; i++) cin >> b[i];
	int cont = a[n-1];
	for(int i = 0; i< n-1; i++){
		if(b[i+1]<a[i]) cont += a[i]-b[i+1];
	}
	cout << cont << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
