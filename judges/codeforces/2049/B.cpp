#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; string s; cin >> n >> s;
	bool allP=true,allS=true;
	int fP=1e9,fS=n-1;
	for(int i = 0; i < n; i++){
		if(s[i]=='p'){
			allS=false;
			fP=min(fP,i);
		}else if(s[i]=='s'){
			allP=false;
			fS=i;
		}
	}
	if(allP||allS||fP==n-1||fS==0) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
