#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n; vector<int> arr(n);
	map<int,int> cnt;
	for(int i = 0; i< n;i++){
		int a; cin >> a;
		cnt[a]++;
	}
	int uno=0,mul=0;
	for(auto [f,s] : cnt){
		if(s == 1) uno++;
		else mul++;
	}
	cout << 2*((uno+1)/2) + mul << endl;
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
