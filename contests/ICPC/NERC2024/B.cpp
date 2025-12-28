#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long n, sum = 0, h, sol = -1; cin >> n;
	vector<long long> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		h = max(h, arr[i]);
	}

	long long l = 0, r = h, mid;
	while(l <= r){
		mid = (l+r) >> 1;
		vector<long long> aux(arr);
		bool pos = true;
		long long R = sum - n*mid, i = 0;
		while(R > 0){
			int c = aux[i] - mid;
			if(c < 0){
				aux[(i+n-1)%n] -= (abs(c)<<1);
				aux[i] = mid;
			}else if (c > 0){
				++c>>=1;
				aux[i] -= c<<1;
				aux[(i+1)%n] += c;
			}
			R -= abs(c);
			++i%=n;
		}
		if(R!=0) pos = false;
		for(int i = 1; i < n; i++) if(aux[i] != aux[0]) pos = false;
		if(pos){
			l = mid+1;
			sol = sum-n*mid;
		}else{
			r = mid-1;
		}
	}
	cout << sol << "\n";
}

int main(){
	int t; cin >> t; while(t--) solve();
}
