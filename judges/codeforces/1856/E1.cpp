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
    sort(sums.begin(), sums.end(), greater<int>());
    for(int i = 0; i < sums.size(); i++){
        if(s1 > s2) s2 += sums[i];
        else s1 += sums[i];
    }
    SUM += s2*s1;
    if(u==1) return SUM;
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
    }
    cout << dfs(adj, visited, 1) << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
