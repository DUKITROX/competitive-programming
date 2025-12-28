#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

template<typename T> istream& operator>>(istream& is, vector<T>& v){for(int i = 0; i < v.size(); i++)is>>v[i];return is;}
template<typename T> ostream& operator<<(ostream& is, vector<T>& v){for(int i = 0; i < v.size(); i++)is<<v[i]<<" ";is<<"\n";return is;}


void solve(){
	int n; cin >> n; vi arr(n); cin >> arr;
	sort(arr.begin(),arr.end());
	
	vi a1(n),a2(n),sum(n,0);
	int tot = 0;

	for(int i = 0; i < n-2; i++){
		if(arr[i]+arr[i+1] <= arr[n-1]){
			a1[i] = lower_bound(arr.begin(), arr.end(), arr[i]+arr[i+1]) - arr.begin();
			a2[a1[i]]++;
			tot++;
		}
	}
	sum[0] = a2[0]; for(int i = 1; i < n; i++) sum[i] = sum[i-1] + a2[i];
	int sol = tot;
	for(int i = n-1; i >= 0; i--){
		sol = min(sol, tot - (sum[n-1]-sum[max(0,i-1)] - n+i));
	}
	cout << sol << "\n";
	
}

int main(){
	int t; cin >> t; while(t--)solve();
}
