/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://cp-algorithms.com/graph/dinic.html
 * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
 * $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */
#pragma once

vi lev, ei;
int dfs(int u, int c) {
    if (u == t) return c;
    for (int &i = ei[u]; i < e[u].size(); i++) {
        int v = e[u][i];
        if (lev[v] <= lev[u] || am[u][v] == 0) continue;
        if (int mc = dfs(v, min(c, am[u][v]))) {
            am[u][v] -= mc, am[v][u] += mc;
            if (am[u][v] == 0) i++;
            return mc;
        }
    }
    return 0;
}
int r = 0;
while (true) {
    queue<int> q; lev.assign(n, -1);
    lev[s] = 0; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : e[u]) {
            if (lev[v] == -1 && am[u][v] > 0) {
                lev[v] = lev[u]+1;
                if (v == t) break;
                q.push(v);
            }
        }
    }
    if (lev[t] == -1) break;

    ei.assign(n, 0);
    while (int f = dfs(s, INF)) r += f;
}