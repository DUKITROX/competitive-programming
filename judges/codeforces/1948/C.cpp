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
string r1,r2; int n;

bool inBounds(int l){
    int i = l/n, j = l%n;
    return (i >= 0 && i < 2 && j >= 0 && j < n);
}

int tr(int u){
    int i = u/n, j = u%n;
    if(!i){
        if(r1[j] == '<' && j >= 0) return --u;
        else if(j < n) return ++u;
        else return -1;
    }else{
        if(r2[j] == '<' && j >= 0) return --u;
        else if(j < n) return ++u;
        else return -1;
    }
}

void dfs(vector<bool>& visited, int u){
    visited[u] = true;
    for(int i = 0; i < 4; i++){
        int v = u-n;
        v = tr(v);
        if(inBounds(v) && !visited[v]) dfs(visited, v);

        v = u+n;
        v = tr(v);
        if(inBounds(v) && !visited[v]) dfs(visited, v);

        v = u-1;
        v = tr(v);
        if(inBounds(v) && !visited[v]) dfs(visited, v);

        v = u+1;
        v = tr(v);
        if(inBounds(v) && !visited[v]) dfs(visited, v);
    }
}

void solve(){
    cin >> n >> r1 >> r2;
    vector<bool> visited(2*n,false);
    dfs(visited, 0);
    if(visited[2*n-1]) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}