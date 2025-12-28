#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

const int INF = 1e9;

void solve(){
    string l, r; cin >> l >> r;
    int n = l.size();
    int dp[11][2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            dp[n][i][j] = 0;
        }
    }

    for(int k = n - 1; k >= 0; k--){
        int dl = l[k] - '0';
        int dr = r[k] - '0';
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                int &res = dp[k][i][j];
                res = INF;
                int lo = i ? dl : 0;
                int hi = j ? dr : 9;
                for(int d = lo; d <= hi; d++){
                    int cost = (d == dl) + (d == dr);
                    int I = i && (d == dl);
                    int J = j && (d == dr);
                    ckmin(res, cost + dp[k+1][I][J]);
                }
            }
        }
    }
    cout << dp[0][1][1] << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

