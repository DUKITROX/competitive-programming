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

void dijkstra(int s, vi & d, vvii& adj) {
    int n = adj.size();
    d.assign(n, INF);

    d[s] = 0;
    priority_queue<ii, vii, greater<ii> > q;
    q.push(make_pair(0,s));
    while (!q.empty()) {
        int v = q.top().second , dV = q.top().first; q.pop();
        if(dV != d[v]) continue;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push(make_pair(d[to],to));
            }
        }
    }
}

void solve(int n, int m){
    vector<vector<pair<int,int>>> adj(n+2);
    for(int i = 0; i < m; i++){
        int u,v,d; cin >> u >> v >> d; u--; v--;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    
    set<int> galos, romanos; int G,R; cin >> G;
    for(int i = 0; i < G; i++){int a; cin >> a; --a; galos.insert(a);}
    cin >> R;
    for(int i = 0; i < R; i++){int a; cin >> a; --a; romanos.insert(a);}

    int megaNodoGalo = n, megaNodoRomano = n+1;
    for(auto e : galos){
        adj[megaNodoGalo].push_back({e, 0});
        adj[e].push_back({megaNodoGalo, 0});
    }
    for(auto e : romanos){
        adj[megaNodoRomano].push_back({e, 0});
        adj[e].push_back({megaNodoRomano, 0});
    }
    vector<int> d1(n+2,INF), d2(n+2, INF);

    dijkstra(megaNodoGalo, d1, adj);
    dijkstra(megaNodoRomano, d2, adj);
    
    int sol = INF; int nodo;
    for(int i = 0; i < n; i++){
        if(!galos.count(i) && !romanos.count(i)){
            if(d1[i] + d2[i] < sol){
                sol = d1[i] + d2[i];
                nodo = i+1;
            }
        }
    }
    cout << nodo << " " << sol << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; while(cin >> n >> m) solve(n,m);
}

/*
4 5
1 2 10
1 3 4
4 1 7
3 2 5
2 4 5
1 1
1 2
*/
