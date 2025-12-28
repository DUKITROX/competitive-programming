#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m; cin >> n >> m;

	set<int> s;
	auto d = [&](int n, int m, int l = -1)->void{
		int g = gcd(n,m); if(l!=-1) g = gcd(g,l);
		for(int i = 1; i*i <= g; i++){
			if(!(g%i))
				s.insert(i),s.insert(g/i);
		}
	};
	d(n-1,m-1);
	d(n-2,m);
	d(n,m-2);
	d(n-2,n,m-1);
	d(m-2,m,n-1);
	cout << s.size() << " ";
	for(auto e : s) cout << e << " ";
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
