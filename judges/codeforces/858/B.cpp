#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int c0=0, c1=0, cR=0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a==0)c0++;
		else if(a==1)c1++;
		else cR++;
	}
	if(cR+c1+1 >= c0)cout << "0\n";
	else if(cR>=1 || c1 == 0)cout<<"1\n";
	else cout << "2\n";
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}

