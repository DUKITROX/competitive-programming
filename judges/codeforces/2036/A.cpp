#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	bool p = true;
	int ant,pre; cin >> ant;
	for(int i = 0; i < n-1; i++){
		int a; cin >> pre;
		if(abs(pre-ant) != 5 && abs(pre-ant) != 7) p = false;
		ant = pre;
	}
	cout << (p?"YES\n":"NO\n");
}

int main(){
	int t; cin >> t; while(t--)solve();
}
