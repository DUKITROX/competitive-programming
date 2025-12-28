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
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.f >> p.s; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.f << " " << p.s; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}

int n,N,M;

void fill(vvii& adj, int u, vector<ll>& grades){
    vi vis(N+1, false);
    vis[u] = true;
    queue<int> q; q.push(u);
    while(!q.empty()){
        int a = q.front(); q.pop();
        for(int i = 0; i < adj[a].size(); i++){
            ll v = adj[a][i].first, c = adj[a][i].second;
            if(!vis[v]){
                vis[v]  = true;
                grades[v] = c - grades[a];
                q.push(v);
            }
        }
    }
}

void dfs(vvii& adj, vector<ll>& dist, int u, vector<ll>& grades, vector<ll>& acum, bool& filled, vi& conj){
    if(grades[u] !=  -1 && !filled){
        filled = true;
        fill(adj, u, grades);
    }
    
    for(int i = 0; i < adj[u].size(); i++){
        ll v = adj[u][i].first, c = adj[u][i].second;
        conj[v] = conj[u];
        if(dist[v] == -1){
            dist[v] = dist[u]+1;
            acum[v] = acum[u] + (dist[v] & 1 ? c : -c);
            dfs(adj, dist, v, grades, acum, filled, conj);
        }else if(abs(dist[u] - dist[v]) % 2 == 0 && !filled){
            grades[v] = abs(acum[u] - acum[v] - (dist[v] & 1 ? c : -c))/2LL;
            filled = true;
            fill(adj, v, grades);
        }
    }
}


bool solve(){
    cin >> N >> n >> M; if(N == 0 && n == 0 && M == 0) return false;
    vvii adj(N+1);
    vi conj(N+1);
    vector<ll> grades(N+1, -1LL), dist(N+1,-1LL), acum(N+1, -1LL);

    for(int i = 0; i < n; i++){
        ll a,b,c; cin >> a;
        if(a == 1){
            cin >> a >> b; grades[a] = b;
        }else{
            cin >> a >> b >> c;
            adj[a].push_back(mp(b,c));
            adj[b].push_back(mp(a,c));
            if(c == 0 || c == 200000) grades[a] = c;
        }
    }
    for(int i = 1; i <= N; i++){
        if(dist[i] == -1LL){
            conj[i] = i;
            acum[i] = dist[i] = 0;
            bool filled = false;
            dfs(adj, dist, i, grades, acum, filled, conj);
        }
    }
    for(int i = 0; i < M; i++){
        int a,b; cin >> a;
        if(a == 1){
            cin >> b;
            if(grades[b] != -1) cout << grades[b] << "\n";
            else cout << "CUIDADO\n";
        }else{
            cin >> a >> b;
            if(grades[a] != -1 && grades[b] != -1) cout << grades[a]+grades[b] << "\n";
            else if(conj[a] == conj[b] && abs(dist[a] - dist[b]) % 2 == 1) cout << abs(acum[a] - acum[b]) << "\n";
            else cout << "CUIDADO\n";
        }
    }
    cout << "---\n";
    return true;
}
/*
2 1 1
2 1 2 0
1 1

12 6 6
2 1 2 6
2 2 3 10
2 3 1 8
2 5 6 22
2 6 7 26
2 7 8 30

1 1
1 3
1 4
1 5
2 5 8
2 5 12

0 0 0
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve());
}