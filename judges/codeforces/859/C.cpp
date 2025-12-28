#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	bool pos = true;
	
	set<char> O,I;
	for(int i = 0; i < n && pos; i++){
		char c = s[i];
		if(i%2 == 1){
			if(O.count(c)) pos = false;
			I.insert(c);
		}else{
			if(I.count(c)) pos = false;
			O.insert(c);
		}
	}
	if(pos)cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
}

