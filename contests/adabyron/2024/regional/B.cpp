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

int bfs(int s, int t, vi& parent, vvi& capacity, vvi& adj) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int> > q;
    q.push(make_pair(s,INF));

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push(make_pair(next, new_flow));
            }
        }
    }
    return 0;
}
int maxflow(int s, int t, vvi& capacity, vvi& adj) {
    int flow = 0;
    int n = adj.size();
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent, capacity, adj)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void dfs(int u, const vvi& adj, const vvi& cap, set<int>& s, vector<bool>& vis){
    vis[u] = true;
    for(int v = 0; v < adj.size(); v++){
        if(cap[u][v] && !vis[v]){
            s.insert(v);
            dfs(v,adj,cap,s,vis);
        }
    }
}
void show(vvi& cap){
    for(int i = 0; i < cap.size(); i++){
        for(int j = 0; j < cap.size(); j++)
            cout << cap[i][j] << " ";
        cout << "\n";
    }
}
void solve(){
    int n,m; cin >> n >> m;
    vvi adj(n);
    vvi cap(n, vi(n,0));
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >>b;
        adj[a].push_back(b);
        cap[a][b] = 1;
    }
    cout << maxflow(0,n-1,cap,adj) << "\n";
    vector<bool> vis(n,false);
    set<int> s; s.insert(0);
    dfs(0,adj,cap,s,vis);
    for(auto u : s){
        for(auto v : adj[u]){
            if(!s.count(v))
                cout << u << " " << v << "\n";
        }
    }
    //show(cap);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
