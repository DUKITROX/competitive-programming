#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,x,y; cin >> n >> x >> y;
	vector<int> arr(n+1); arr[x] = 0; arr[y] = 1;
	int p = 1;
	for(int i = x+1; i < y; i++){
		if(i==x+1 && (y-x)%2==0) arr[i] = 2;
		else{
			arr[i] = p;
			p ^= 1;
		}
	}
	int d = n-y+x-1; p = 1;
	for(int i = 1; i <= d; i++){
		int pos = x-i; if(pos < 1) pos = n+x-i;
		if(i == 1 && d%2==1) arr[pos] = 2;
		else{
			arr[pos] = p;
			p ^= 1;
		}
	}
	for(int i = 1; i <= n; i++) cout << arr[i] << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
