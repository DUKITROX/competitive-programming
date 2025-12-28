#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >>y2;
	if(x2-y2+y1 > x1 || y2 < y1) {
		cout << "-1\n";
		return;}
	else{
		cout << x1-(x2-y2+y1) + y2-y1 << "\n";
		return;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}
