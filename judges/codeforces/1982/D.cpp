#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
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
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.first >> p.second; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.first << " " << p.second; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; os << "\n"; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

int n,m,k;
ll val(int i, int j, vector<vector<ll> >& prefix){
    return (prefix[i+k-1][j+k-1] - (j>0?prefix[i+k-1][j-1]:0) - (i>0?prefix[i-1][j+k-1]:0) + (i>0&&j>0?prefix[i-1][j-1]:0));
}
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    ll d = gcd(b, a % b);
    return d;
}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
void solve(){
    cin >> n >> m >> k; vector<vector<int> > arr(n, vector<int>(m)); cin >> arr; vector<string> map(n); cin >> map;
    vector<vector<ll> > prefix(n, vector<ll>(m,0)); ll D = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i) prefix[i][j] += prefix[i-1][j];
            if(j) prefix[i][j] += prefix[i][j-1];
            if(i&&j) prefix[i][j] -= prefix[i-1][j-1];
            prefix[i][j] += (map[i][j]=='1'?1:-1);
            D += arr[i][j]*(map[i][j]=='1'?1:-1);
        }
    }
    ll GCD = abs(val(0,0,prefix));
    for(int i = 0; i < n-k+1; i++)
        for(int j = 0; j < m-k+1; j++)
            GCD = gcd(GCD,abs(val(i,j,prefix)));
    cout << ((GCD==0&&D==0) || (GCD != 0 && D%GCD == 0) ? "YES\n" : "NO\n");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;while(t--)solve();
}