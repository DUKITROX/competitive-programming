#include <bits/stdc++.h>
using namespace std;

int main(){
	int tt; cin >> tt; while(tt--) {
		int n,x; cin >> n >> x;
		int sol = 0;
		for(int i = 0; i < n; i++){
			int a; cin >> a; sol += a;
		}
		cout << (sol%n == 0 && sol/n == x ? "YES":"NO") << "\n";
	}
}
