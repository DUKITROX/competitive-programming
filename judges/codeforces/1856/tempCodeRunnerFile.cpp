#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

ll SUM = 0;

ll dfs(vvll& adj, vb& visited, ll u){ // Devuelve la cantidad de hijos de u
    visited[u] = true;
    vll sums;
    ll s1=0,s2=0,res=1;
    for(auto &v : adj[u]){
        if(!visited[v]){
            sums.push_back(dfs(adj, visited, v));
            res += *(sums.end()-1);
        }
    }
    for(int i = 0; i < sums.size(); i++) s1 = max(s1, sums[i]);
    for(int i = 0; i < sums.size(); i++) s2 += sums[i];
    s2 -= s1;
    SUM += s2*s1;
    return res;
}

void solve(){
    ll n,v,ini; cin >> n;
    vvll adj(n+1);
    vb visited(n+1, false);
    for(int i = 2; i <= n; i++){
        cin >> v;
        adj[i].push_back(v);
        adj[v].push_back(i);
        if(adj[i].size() > 2) ini = i;
        if(adj[v].size() > 2) ini = v;
    }
    ll M = 0;
    for(int i = 1; i <= n; i++){
        SUM = 0;
        visited.assign(n+1, false);
        dfs(adj, visited, i);
        M = max(M,SUM);
    }
    cout << M << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}