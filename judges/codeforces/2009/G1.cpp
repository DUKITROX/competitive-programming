#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define mp(f,s) make_pair(f,s)

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

void solve(){
    int n,k,q; cin >> n >> k >> q; vi arr(n); cin >> arr; vi dist(n);
    map<int,int> m; set<ii> s;
    for(int i = 0; i < n; i++) dist[i] = arr[i]-i;
    for(int i = 0; i < k; i++) m[dist[i]]++;
    for(const auto& e : m) s.insert(make_pair(e.second,e.first));
    vi sol(n-k+1);
    for(int i = 0; i < n-k+1; i++){
        ii elem = *s.rbegin();
        sol[i] = k-elem.first;
        s.erase(mp(m[dist[i]],dist[i])); m[dist[i]]--; s.insert(mp(m[dist[i]],dist[i]));
        s.erase(mp(m[dist[i+k]],dist[i+k])); m[dist[i+k]]++; s.insert(mp(m[dist[i+k]],dist[i+k]));
    }
    for(int i = 0; i < q; i++){int a,b; cin >> a >> b; cout << sol[--a] << "\n";}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}
