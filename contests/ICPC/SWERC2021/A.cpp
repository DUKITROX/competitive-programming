#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	map<int,int> m;
	for(int i = 0; i< n; i++){
		int a,b; cin>>b>>a;
		m[a] = max(m[a],b);
	}
	int sol = 0;
	if(m.size()<10) cout << "MOREPROBLEMS\n";
	else{
		for(auto [e,s]: m) sol += s;
		cout << sol << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
