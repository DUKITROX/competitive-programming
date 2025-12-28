#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;
typedef long long int ll;
typedef struct { int v; ll cap, flow; } edge;
typedef struct { int u, v; ll flow; } SpeEdge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = LLONG_MAX;

class max_flow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<bool> alcanzable;
    vector<ii> p;

    bool BFS(int s, int t) {
        d.assign(V, -1); d[s] = 0;
        queue<int> q({ s });
        p.assign(V, { -1,-1 });
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (auto& idx : AL[u]) {
                edge& v = EL[idx];
                if ((v.cap - v.flow > 0) && (d[v.v] == -1)) {
                    d[v.v] = d[u] + 1; q.push(v.v); p[v.v] = { u, idx };
                }

            }

        }
        return d[t] != -1;
    }

    ll send_onde_flow(int s, int t, ll f = INF) {
        if (s == t) return f;
        ii u = p[t];
        ll& cap = EL[u.second].cap; ll& flow = EL[u.second].flow;
        ll pushed = send_onde_flow(s, u.first, min(f, cap - flow));
        flow += pushed;
        EL[u.second ^ 1].flow -= pushed;
        return pushed;
    }

    ll DFS(int u, int t, ll f = INF) {
        if ((u == t) || (f == 0)) return f;
        for (int& i = last[u]; i < (int)AL[u].size(); i++) {
            edge& v = EL[AL[u][i]];
            if (d[v.v] != d[u] + 1) continue;
            if (ll pushed = DFS(v.v, t, min(f, v.cap - v.flow))) {
                v.flow += pushed;
                EL[AL[u][i] ^ 1].flow -= pushed;
                return pushed;

            }
        }
        return 0;
    }


public:
    max_flow(int initialV) : V(initialV) {
        EL.clear();
        alcanzable.assign(V, false);
        AL.assign(V, vi());
    }

    void add_edge(int u, int v, ll w) {
        if (u == v) return;
        EL.push_back({ v, w, 0 });
        AL[u].push_back(EL.size() - 1);
        EL.push_back({ u, 0, 0 });
        AL[v].push_back(EL.size() - 1);
    }

    ll dinic(int s, int t) {
        ll mf = 0;
        while (BFS(s, t)) {
            last.assign(V, 0);
            while (ll f = DFS(s, t))
            {
                mf += f;
            }
        }
        return mf;
    }



};
int fil[] = { 1, 0, -1, 0 };
int col[] = { 0, 1, 0, -1 };

int main() {
    cin.sync_with_stdio(false);
    cout.tie(nullptr);
    int num;
    cin >> num;
    while (num--)
    {
        int r, c; cin >> r >> c;
        vector<vector<char>> mapa(r, vector<char>(c));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> mapa[i][j];
            }
        }
        max_flow flow(2 * r * c);
        int s, t;
        unordered_map<int, bool> ma;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mapa[i][j] != '#') {
                    if (mapa[i][j] == 'L') s = c * i + j;
                    if (mapa[i][j] == 'C') {
                        t = c * i + j;
                     
                        for (int k = 0; k < 4; k++)
                        {
                            int ni = i + fil[k]; int nj = j + col[k];
                            if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                                ma[ni * c + nj] = true;
                            }

                        }
                        continue;
                    }
                
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + fil[k]; int nj = j + col[k];
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                            if (mapa[ni][nj] != '#' && mapa[ni][nj]!='L') {
                                flow.add_edge(c * r + (c * i + j), (c * ni + nj), INF);
                            }

                        }


                    }

                }
            }
        }

        
        for (int i = 0; i < r * c; i++)
        {
            if (i != s && i != t && !ma[i]) {
                flow.add_edge(i, r * c + i, 1);
            }
            else {
                flow.add_edge(i, r * c + i, INF);
                
            }
        }

        ll tot = flow.dinic(s ,r*c+ t);
        if (tot== INF) {
            cout << "IMPOSIBLE\n";
        }
        else {
            cout << tot << "\n";
        }
    }
    return 0;
}