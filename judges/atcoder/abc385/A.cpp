#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a,b,c; cin >> a >> b >> c;
	if(a+b==c||a+c==b||b+c==a||(a==b&&b==c)) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
