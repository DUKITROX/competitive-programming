#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	vector<int> m(n);
	int l = 0, r = 0;
	bool ok = true;

	for(int i = 0; i < n && ok; i++){
		if(i >= n/2 && s[i] == 'W' && !m[i]) ok = false;
		else if(!m[i]){
			m[i] = -1;
			if(s[i] == 'W'){
				for(int r + 1; i < n/2; i++){
					if(s[r] == 'W' && !m[r])
						break;
				}
				if(r >= n/2) ok = false;
				else m[r] = 1;
			}
			for(int j = 0; j < n; j++){
				
			}
		}
	}
}

int main(){
	int tt; cin >> tt; while(t--)solve();
}
