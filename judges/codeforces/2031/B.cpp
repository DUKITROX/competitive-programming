#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n; vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	bool pos = true;
	for(int i = 0; i < n; i++){
		if(arr[i] != i+1){
			bool p1 = true, p2 = true;
			if(i!=0)
				if(arr[i] != i || arr[i-1] != i+1) p1 = false;
			if(i != n-1)
				if(arr[i] != i+2 || arr[i+1] != i+1) p2 = false;
			if(!p1 && !p2) pos = false;

			if(i == 0 && n > 1 && (arr[i] != i+2 || arr[i+1] != i+1)) pos = false;
			if(i == n-1 && n > 1 && (arr[i] != i || arr[i-1] != i+1)) pos = false;
		}
	}
	cout << (pos?"YES":"NO") << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
