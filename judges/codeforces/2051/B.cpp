#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,a,b,c; cin >> n >> a >> b >> c;
	int sum = a+b+c; int res = 3*(n/sum);n%=sum;
	if(n>0) {res++; n-=a;}
	if(n>0){res++;n-=b;}
	if(n>0){res++;n-=c;}
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
