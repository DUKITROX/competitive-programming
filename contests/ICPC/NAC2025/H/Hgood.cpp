#include <bits/stdc++.h>

#define int long long

using namespace std;

int _d = 0;

int n, k;
vector<int> w;
vector<vector<int>> e;

vector<int> used;
pair<int, pair<int, int>> dfs(int u) {
    int sum = 0, children_sum_min = 0, children_sum_max = 0;
    for (auto v : e[u]) {
        if (!used[v]) {
            used[v] = true;
            auto [children_sum, children_min_max] = dfs(v);
            if (children_sum == -1)
                return {-1, {-1, -1}};
            sum += children_sum;
            children_sum_min += children_min_max.first;
            children_sum_max += children_min_max.second;
        }
    }
    if (w[u] != -1) {
        if (children_sum_min+w[u] > k)
            return {-1, {-1, -1}};
        int new_sum;
        if (children_sum_max+w[u] > k)
            new_sum = sum-(children_sum_max+w[u]-k)+w[u];
        else
            new_sum = sum+w[u];
        return {new_sum, {w[u], w[u]}};
    }
    if (children_sum_min > k)
        return {-1, {-1, -1}};
    int new_sum, value;
    if (children_sum_max > k)
        new_sum = sum-(children_sum_max-k), value = 0;
    else
        value = k-children_sum_max, new_sum = sum+value;
    return {new_sum, {0, value}};
}
signed main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#endif
    
    cin >> n >> k;
    w.resize(n);
    for (int i = 0; i < n; i++) 
        cin >> w[i];

    e.assign(n, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v; u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    used.assign(n, false);
    used[0] = true;
    cout << dfs(0).first << "\n";
    // for (int i = 0; i < n; i++)
    //     assert(used[i] == true);

    return 0;
}
