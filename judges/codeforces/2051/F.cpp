#include <bits/stdc++.h>
#include <tr2/dynamic_bitset>
using namespace std;

void solve(){
	int n,m,q; cin >> n >> m >> q;
	bitset<1000000005> bs; bs[--m] = 1;
	for(int i = 0; i < q; i++){
		bitset<100000005> mask(1);
		int a; cin >> a;a--;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	boost::dynamic_bitset<> mask(1000000005);
	int t; cin >> t; while(t--) solve();
}
