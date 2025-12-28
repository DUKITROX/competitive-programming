#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n; cin >> n; vector<int> a(n),b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	int cont = 0;
	set<int> s,B;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!s.count(a[i] + b[j]) && !B.count(j))	{
				cont++;
				s.insert(a[i] + b[j]);
				B.insert(j);
			}
		}
	}

	cout << (cont>2?"YES":"NO") << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
