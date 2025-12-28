#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define f first
#define s second
#define mp make_pair
#define sort(x) sort(x.begin(), x.end())
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.f >> p.s; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.f << " " << p.s; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}

int dp(int n, vi& memo, int pos[5]){
    if(n < 0) return 1e9;
    if(n == 0) return 0;
    if(memo[n]) return memo[n];

    int ans = 1e9;
    for(int i = 0; i < 5; i++)
        ans = min(ans, dp(n-pos[i], memo, pos)+1);
    return memo[n] = ans;
}
struct UFDS{
    vector<ll> p,setSize;
    int numSets;
    UFDS(int n){
        p.assign(n,0);
        setSize.assign(n,1);
        numSets = n;
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
    void merge(int x, int y){
        int i = find(x); int j = find(y);
        if(i==j) return;
        p[i] = j;
        setSize[j] += setSize[i];
        numSets--;
    }
    int size(int i) {return setSize[find(i)];}
};
void solve(){
    int n; cin >> n;
    int pos[5] = {15,10,6,3,1};
    int ans = 0,i=0;
    int N = 600000;
    ans = (N/15)*(n/N);
    n %= N;
    vi memo(N+1,0);
    cout << ans + dp(n,memo,pos) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}