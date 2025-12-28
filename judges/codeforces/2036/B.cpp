#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,k; cin >> n >> k;
	vector<int> b(k+1,0),c(k);
	for(int i = 0; i < k; i++){
		int B,C; cin >> B >> C;
		b[B] += C;
	}
	sort(b.begin(),b.end(),greater<int>());
	long long sol = 0;
	for(int i = 0; i < min(n,k); i++) sol += b[i];
	cout << sol << endl;
}

signed main(){
	int t; cin >> t; while(t--)solve();
}
