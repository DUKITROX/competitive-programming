#include <bits/stdc++.h>
using namespace std;

void solve(){

}
#define int long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; while(cin >> n && n){

		int M,act,j=0; cin >> M;
		for(int i = 1; i < n; i++) {
			cin >> act;
			if(act < M ) j = i+1;
			M = max(act,M);
		}
		cout << n-j << "\n";
	}
}
