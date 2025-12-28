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
void IS_CUTPOINT(int u){}
void dfs(int v, const vvi& adj, vi& low, vi& tin, vector<bool> visited, int& timer, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, adj, low, tin, visited, timer, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    } 
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}
void find_cutpoints(const vvi& adj) {
    int n = adj.size();
    int timer = 0;
    vector<bool> visited(n,false);
    vi tin(n,-1), low(n,-1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i, adj, low, tin, visited, timer);
}