#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int n, k, s, e;
    while(cin >> n >> k >> s >> e && n && k && s && e){
        vector<vector<int>> adj(n*n+1);
        for(int i = 0; i < s+e; i++){
            int a,b; cin >> a >> b;
            for(int j = 1; j <= k; j++){
                adj[max(1,i-j)].push_back(b);
            }
        }

        queue<int> q; q.push(1);
        vector<int> d(n*n+1, INF); d[1] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int i = 1; i <= min(k,n*n); i++) { // dado
                if(d[u+i] == INF){
                    q.push(u+i);
                    d[u+i] = d[u]+1;
                }
            }
            for(auto v : adj[u]){ // serpiente/escalera
                if(d[v] == INF){
                    q.push(v);
                    d[v] = d[u] + 1;
                }
            }
        }
        cout << d[n*n] << "\n";
    }
}