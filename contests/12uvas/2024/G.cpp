#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//gcd(a,b) = a*x + b*y
int gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		 x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void solve(){
	int  a,b,x,y; cin >> a >> b;
	cout << a/gcd(a,b,x,y) + b/gcd(a,b,x,y) - 1 <<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
