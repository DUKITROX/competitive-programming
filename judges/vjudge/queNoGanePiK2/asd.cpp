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
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

void bellmanFord(const vvi& arr, vector<ll>& d, vi& p){
    int
}


void solve(){
    int n, m; cin >> n >> m;
    vvi arr(m, vi(3)); cin >> arr;
    vector<ll> d(n+1, INF); d[1] = 0;
    vi p(n+1, -1);

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int u = arr[j][0], v = arr[j][1], w = arr[j][2];
            if(d[u] < INF && d[v] > d[u] + w){
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }
    for (int j = 0; j < m; ++) {
        int u = arr[j][0], v = arr[j][1], w = arr[j][2];
        if (d[u] < INF && d[u] + w < dist[v]) {
            // negative cycle found
            return;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}