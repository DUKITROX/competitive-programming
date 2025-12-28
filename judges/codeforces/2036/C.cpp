#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s; cin >> s; int q; cin >> q;
	set<int> si;
	for(int i = 0; i < s.length()-3; i++){
		if(s.substr(i,4) == "1100") si.insert(i);
	}
	for(int i = 0; i < q; i++){
		int a; char b; cin >> a >> b;a--;
		s[a] = b;
		for(int j = max(0,a-3); j <= a; j++){
			if(s.substr(j,4) == "1100") si.insert(j);
			else si.erase(j);
		}
		cout << (si.empty()?"NO\n":"YES\n");
	}
}

int main(){
	int t; cin >> t; while(t--)solve();
}
