#pragma GCC optimize ("03")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

void solve(){
    int r,w,h; cin >> r >> w >> h;
    r <<= 1;
    int ans = 0;

    for(int p = 0; p < 2; p++){
        int dt = 10000;
        auto scan = [&](int L, int R, int dt)->pair<int,int>{
            int C=L,V=0;
            __int128 rr = r;

            for(int i = L; i <= R; i += dt){
                if(i < 0) continue;
                __int128 W = i*w;
                if(W > rr) continue;
                __int128 H = (__int128)rr*rr - W*W;

                int lo = 0, hi = 2e9;
                while(lo < hi){
                    int mid = (lo+hi+1)/2;
                    __int128 val = (__int128)mid*mid*h*h;
                    if(val <= H) lo = mid;
                    else hi = mid-1;
                }

                if(ckmax(V, i*lo))
                    C = i;

            }

            return {C,V};
        };
        auto [C,_] = scan(0,r,dt);
        if(ckmax(ans, scan(C-dt, C+dt, 1).second))
			dbg(scan(C-dt,C+dt,1).second);
        swap(w,h);
    }
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n = 10;
    int tt; cin >> tt; while(tt--) solve();
}
