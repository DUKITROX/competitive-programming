#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isPrime(int n) {
    if (n <= 1LL) return false;
    if (n <= 3LL) return true;            
    if (n % 2LL == 0LL || n % 3LL == 0LL) return false;
    for (int i = 5LL; 1LL * i * i <= n; i += 6LL) 
        if (n % i == 0LL || n % (i + 2LL) == 0LL)
            return false;
    return true;
}

void solve(){
	int64_t n,k; cin >> n >> k;
	if(n == 1){
		for(int i = 0; i < k-1; i++){
			n *= 10;
			n++;
		}
		if(isPrime(n)) cout << "YES\n";
		else cout << "NO\n";
	}
	else if(k == 1LL && isPrime(n)) cout << "YES\n";
	else cout << "NO\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
