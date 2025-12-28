#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k; cin >> n >> k;
	if(n==1) cout << "1\n1\n";
	else if((k-1)%2 == 1){
		cout << "3\n1 " << k << " " << k+1 <<"\n";
	}else if(k > 2 && k < n-1){
		cout << "3\n1 " << k-1 << " " << k+2 << "\n";
	}else cout << "-1\n";

}
int main(){
	int t; cin >> t; while(t--) solve();
}
