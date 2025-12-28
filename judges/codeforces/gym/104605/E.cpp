#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

void solve(){
	int n,k,x,key;
	#ifdef LOCAL
		x = rand()%(1<<6);
		n = rand()%(1<<6) + x + 2;
		key = rand()%n;
	#else
		cin >> n; k = n;
	#endif
	while(__builtin_popcount(k) != 1) k -= LSOne(k);
	int sol = 0, mask;

	#ifdef LOCAL
		mask = key&x; sol |= mask;
		mask = abs(key-k+1)&x; sol |= mask;
		mask = abs(key-n+1)&x; sol |= mask;
		mask = abs(key-n+k)&x; sol |= mask;
		cout << x << " ";
	#else
		cout << "? 0" << endl; cin >> mask; sol |= mask;
		cout << "? " << k-1 << endl; cin >> mask; sol |= mask;
		cout << "? " << n-1 << endl; cin >> mask; sol |= mask;
		cout << "? " << n-k << endl; cin >> mask; sol |= mask;
	#endif
	cout << "! " << sol << endl;
	#ifndef LOCAL
		char c; cin >> c; if(c == '-') return;
	#endif
}

int main(){
	int tt; cin >> tt; while(tt--) solve();
}
