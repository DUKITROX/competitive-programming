/**
 * Author: chilli, Takanori MAEHARA, Benq, Simon Lindholm
 * Date: 2019-05-10
 * License: CC0
 * Source: https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence.cc
 * and https://github.com/bqi343/USACO/blob/42d177dfb9d6ce350389583cfa71484eb8ae614c/Implementations/content/graphs%20(12)/Advanced/DirectedMST.h for the reconstruction
 * Description:
 * Time: O(E \log V)
 * Status: Stress-tested, also tested on NWERC 2018 fastestspeedrun
 */
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;

class max_flow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t){
        d.assign(V, -1); d[s]=0;
        queue<int> q({s});
        p.assign(V, {-1, -1});
        while(!q.empty()){
            int u = q.front(); q.pop();
            if (u == t) break;
            for(auto &idx : AL[u]){
                auto &[v, cap, flow] = EL[idx];
                if ((cap-flow>0) && (d[v]==-1))
                    d[v]=d[u]+1, q.push(v), p[v]={u, idx};
            }
        }
        return d[t] != -1;
    }

    ll send_one_flow(int s, int t, ll f = INF){
        if (s==t) return f;
        auto &[u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap-flow));
        flow += pushed;
        auto &rflow = get<2>(EL[idx^1]);
        rflow -= pushed;
        return pushed;
    }

    ll DFS(int u, int t, ll f = INF){
        if ((u==t) || (f==0)) return f;
        for (int &i = last[u]; i<(int)AL[u].size(); ++i){
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u]+1) continue;
            if (ll pushed = DFS(v, t, min(f, cap-flow))){
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i]^1]);
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
public:
    max_flow(int initialV): V(initialV){
        EL.clear();
        AL.assign(V, vi());
    }

    void add_edge(int u, int v, ll uv, ll vu=0){
        if (u == v) return;
        EL.emplace_back(v, uv, 0);
        AL[u].push_back(EL.size()-1);
        EL.emplace_back(u, vu, 0);
        AL[v].push_back(EL.size()-1);
    }

    ll edmonds_karp(int s, int t){
        ll mf = 0;
        while(BFS(s, t)){
            ll f = send_one_flow(s, t);
            if (f==0) break;
            mf += f;
        }
        return mf;
    }

    ll dinic(int s, int t){
        ll mf = 0;
        while (BFS(s, t))
        {
            last.assign(V, 0);
            while (ll f = DFS(s, t))
                mf += f; 
        }
        return mf;   
    }

    int in(int v){return v;}
    int out(int v){return V+v;}
};