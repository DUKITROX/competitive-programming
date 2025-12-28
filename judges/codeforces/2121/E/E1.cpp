#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { 
    if (b < a) { a = b; return true; } 
    return false; 
}

void solve(){
    string l, r;
    cin >> l >> r;
    int n = l.size();
    const int INF = 1e9;
    // dp[pos][tightL][tightR] = minimum cost from pos to end
    static int dp[11][2][2];
    // initialize dp at position n
    for(int tL = 0; tL < 2; tL++){
        for(int tR = 0; tR < 2; tR++){
            dp[n][tL][tR] = 0;
        }
    }
    // build dp backwards
    for(int i = n - 1; i >= 0; i--){
        int dl = l[i] - '0';
        int dr = r[i] - '0';
        for(int tL = 0; tL < 2; tL++){
            for(int tR = 0; tR < 2; tR++){
                int &res = dp[i][tL][tR];
                res = INF;
                int lo = tL ? dl : 0;
                int hi = tR ? dr : 9;
                for(int d = lo; d <= hi; d++){
                    int cost = (d == dl) + (d == dr);
                    int ntL = tL && (d == dl);
                    int ntR = tR && (d == dr);
                    ckmin(res, cost + dp[i+1][ntL][ntR]);
                }
            }
        }
    }
    // answer is dp[0][1][1]
    cout << dp[0][1][1] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}

