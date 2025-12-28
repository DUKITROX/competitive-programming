#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m = 1; cin >> n;
	int p[n] = {0};
	auto same = [](int a, int b) -> bool{
		cout << "? " << a << " " << b << endl;
		int r; cin >> r;
		if(r == -1) exit(0);
		return !r;
	};
	while(!same(1,++m)); p[m] = 1;
	for(int i = m+1; i < n; i++){
		p[i] = p[i-1];
		while(!same(i,++p[i]));
	}
	cout << "!";
	for(int i = 1; i < n; i++) cout << " " << p[i];
	cout << endl;
}

int main(){
	int t; cin >> t; while(t--)solve();
}
