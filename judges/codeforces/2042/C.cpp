#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k; cin >> n >> k;
	string s; cin >> s;
	vector<int> cum(n);
	cum[n-1] = (s[n-1]=='0'?-1:1);
	for(int i = n-2; i >= 0; i--){
		cum[i] = cum[i+1] + (s[i]=='0'?-1:1);
	}
	int sum = 0, cont = 1;
	cum.erase(cum.begin());
	sort(cum.begin(), cum.end(), greater<int>());
	while(sum < k && cont < n){
		if(cum[cont-1] < 0) break;
		sum += cum[cont-1];
		cont++;
	}
	cout << (sum >= k ? cont : -1) << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
