#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

void dijkstra(int s, vi & d, vvii& adj) {
    int n = adj.size();
    d.assign(n, INF);

    d[s] = 0;
    priority_queue<ii, vii, greater<ii> > q;
    q.push(make_pair(0,s));
    while (!q.empty()) {
        int dV = q.top().first, v = q.top().second; q.pop();
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

void insert(map<string,int> &m, string s, int &i, vvii &adj){
    vii arr;
    for(char c = 'a'; c <= 'z'; c++){
        m[c+s] = i;
        adj.push_back(arr);
        i++;
    }
}

bool solve(){
    int n; cin >> n; if(!n) return false;

    set<string> s; map<string,int> m;
    vvii adj(2);
    int cont = 2;

    string ini,fin; cin >> ini >> fin;
    insert(m, ini, cont, adj); s.insert(ini);
    insert(m, fin, cont, adj); s.insert(fin);
    for(char c = 'a'; c <= 'z'; c++){
        adj[0].push_back(make_pair(m[c+ini],0));
        adj[m[c+fin]].push_back(make_pair(1,0));
    }

    for(int i = 0; i < n; i++){
        string s1,s2,v; cin >> s1 >> s2 >> v;
        if(!s.count(s1)) insert(m, s1, cont, adj); s.insert(s1);
        if(!s.count(s2)) insert(m, s2, cont, adj); s.insert(s2);
        
        for(char c = 'a'; c <= 'z'; c++){
            if(c != v[0]) {
                adj[m[c+s1]].push_back(make_pair(m[v[0]+s2], v.length()));
                adj[m[c+s2]].push_back(make_pair(m[v[0]+s1], v.length()));
            }
        }
    }

    vi d(m.size());
    dijkstra(0, d, adj);
    if(d[1] == INF) cout << "impossivel\n";
    else cout << d[1] << "\n";
    return true;
}
/*
4
portugues frances
ingles espanhol red
espanhol portugues amigo
frances ingles date
espanhol ingles actual
4
portugues alemao
ingles espanhol red
espanhol portugues amigo
frances ingles date
espanhol ingles actual
6
portugues frances
ingles espanhol red
espanhol portugues amigo
frances ingles date
frances espanhol la
portugues ingles a
espanhol ingles actual
0*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve());
}
