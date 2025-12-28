#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s; cin >> s;
	int cont = 0, ind = -1;
	for(int i = 0; i < s.size();  i++){
		if(ind == -1){
			if(s[s.size()-1-i] != '0') {
				ind = i;
			}else cont++;
		}else{
			if(s[s.size()-1-i] != '0') cont++;
		}
	}
	cout << cont << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
