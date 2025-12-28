#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int64_t __lego(int64_t x) {
    int64_t res = -1;
    while (x > 0) {
        x >>= 1;
        ++res;
    }
    return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 dp[128][128];for(int i = 0; i < 128; i++) for(int j = 0; j < 128; j++) dp[i][j] = 1e18;

	for(int i = 0; i <= 60; i++) dp[i][i] = 0;
	for(int k = 1; k <= 60; k++){
		for(int i = 127; i >= 0; i--){
			for(int j = 127; j >= 0; j--){
				dp[i][j] = min({dp[i][j], (i-k >= 0 ? dp[i-k][j] + (1LL<<k) : (i64)1e18), (j-k >= 0 ? dp[i][j-k] + (1LL<<k) : (i64)(1e18))});
			}
		}
	}

	int tt; cin >> tt; while(tt--){
		i64 x,y; cin >> x >> y;
		if(y > x) swap(x,y);
		int a = __lego(x), b = (__lego(y));
		int n = __lego(y ^ (x >> (a-b)))+1;
		int m = n + a-b;
		if(n==1&&m==1){
			if(!(x>>1)) cout << "6\n";
			else if(!(x>>2)) cout << "12\n";
			else cout << "14\n";
		}else if(n==2&&m==2){
			if(!(x>>2)) cout << "12\n";
			else cout << "14\n";
		}else
			cout << dp[n+60][m+60] << "\n";
	}
}
