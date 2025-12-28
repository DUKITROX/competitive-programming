#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const ll INF = LLONG_MAX;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p, vector<vector<pair<ll, ll> > >& adj) {
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push(make_pair(d[to], to));
            }
        }
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll> > > adj(n);
    vector<ll> d(n), p(n);
    for(ll i = 0; i < m; i++){
        ll a,b,c; cin >> a >> b >> c; a--;b--;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    dijkstra(0, d, p, adj);
    for(ll i = 0; i < n; i++){
        //cout << i << " : " << d[i] << "\n";
    }
    if(d[n-1] == INF) cout << "inf\n";
    else{
        vii sol;
        set<ll> res;
        vector<pair<string,ll> > SOL;
        for(ll i = 0; i < n; i++){
            sol.push_back(make_pair(d[i],i));
        }
        sort(sol.begin(), sol.end());

        ll dist = 0, DIST = 0;
        ll i = 0, cont = 0;
        //for(ll  i = 0; i < n; i++) cout << sol[i].second << " : " << sol[i].first << endl;
        while(i < n-1 && cont <= n*n){
            string s;
            ll t;
            while(sol[i].first <= dist && i < n){
                res.insert(sol[i].second);
                i++;
            }
            if(i < n) {
                DIST = dist;
                dist = sol[i].first; 
            }

            for(ll i = 0; i < n; i++){
                if(res.count(i)) s += "1";
                else s += "0";
            }
            t = dist - DIST;
            if(!res.count(n-1)) SOL.push_back(make_pair(s,t));
            cont++;
        }
        cout << d[n-1] << " " << SOL.size() << "\n";
        for(int i = 0; i < SOL.size(); i++) cout << SOL[i].first << " " << SOL[i].second << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
