#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	if(!(n%2))
		for(int i = 0; i < n; i++) cout << i/2+1 << " ";
	else if(n < 27)
		cout << "-1";
	else{
		for(int i = 0; i < n; i++){
			if(i == 0 || i == 9 || i == 25) cout << 1e6-5 << " ";
			else if(i == 22 || i == 26) cout << 1e6-4 << " ";
			else if(i < 9) cout << (i+1)/2+1 << " ";
			else if(9 < i && i < 22) cout << i/2+1 << " ";
			else cout << ((i+1)/2)+1 << " ";
		}
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
