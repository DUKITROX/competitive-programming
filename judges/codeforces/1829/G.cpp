#include <bits/stdc++.h>
using namespace std;


const int INF = 1000000;
long long dp[INF+1];

void solve(){
    int n;cin >> n; cout << dp[n] << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int inc1 = 0, inc2;
    for(int i = 1; i <= INF; i += inc1){
        inc2 = inc1+1;
        long long acum = 0;

        for(int j = i; j <= INF; j+=inc2){
            dp[j] = ((long long)(j) * (long long)(j));
            if(j!=i) dp[j] += acum;
            acum += ((long long)(j) * (long long)(j));
            if(i != 1) dp[j] += dp[j-inc2+1];
            inc2 += 1;
        }
        inc1 += 1;
    }
    int t;cin>>t;while(t--)solve();
}