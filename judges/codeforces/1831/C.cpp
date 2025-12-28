#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;
const int INF = 1e9 + 7;

int sol;

void dfs(int u, vvii& arr, vb& visited, vi& dp, vi& ind){
    visited[u] = true;
    for(auto v : arr[u]){
        if(!visited[v.first]){
            ind[v.first] = v.second;
            if(ind[v.first] > ind[u]){
                dp[v.first] = dp[u];
            }else{
                dp[v.first] = dp[u] + 1;
            }
            dfs(v.first, arr, visited, dp, ind);
        }
    }
    sol = max(sol,dp[u]);
}

void solve(){
    int n;cin>>n;
    vvii arr(n);
    vi dp(n+1,INF), ind(n+1);
    vb visited(n,false);
    sol = -1;
    dp[0] = 1;
    ind[0] = 0;
    for(int i = 0; i < n-1; i++){
        int a,b;cin >>a>>b;a--;b--;
        arr[a].push_back(make_pair(b,i+1));
        arr[b].push_back(make_pair(a,i+1));
    }
    dfs(0, arr, visited, dp, ind);
    cout << sol << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}