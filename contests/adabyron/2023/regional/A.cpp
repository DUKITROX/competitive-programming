#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, pesos[100001], diff[100000];
	cin >> n;
	for(int i = 0; i < n; i++) cin >> pesos[i];
	sort(pesos, pesos+n);
	for(int i = 0; i < n-1; i++){
		diff[i] = pesos[i+1] - pesos[i];
	}
	sort(diff, diff+n-1, greater<int>());
	int res = pesos[n-1]-pesos[0];

	cout << res << " ";
	for(int i = 0; i < n-1; i++){
		res -= diff[i];
		cout << res << " ";
	}
	cout << endl;
}

int main(){
	int casos;
	cin >> casos;
	while(casos--) solve();
}
