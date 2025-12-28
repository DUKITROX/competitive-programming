#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int tt; cin >> tt; while(tt--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        map<int, vector<pair<int, int>>> color_to_cells;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                color_to_cells[grid[i][j]].emplace_back(i, j);
            }
        }

        int sum = 0;
        int MA = 0;

        for (const auto& entry : color_to_cells) {
            int c = entry.first;
            const auto& cells = entry.second;

            int col = 0;
            unordered_set<int> vis;

            for (const auto& p : cells) {
                int i = p.first;
                int j = p.second;
                int key = i * m + j;

                if (vis.find(key) == vis.end()) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    vis.insert(key);
                    map<int, int> col_ma;
                    col_ma[key] = 0;
                    bool is_bipartite = true;
                    int comp = 0;

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        comp++;

                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == c) {
                                int nkey = nx * m + ny;
                                if (vis.find(nkey) == vis.end()) {
                                    vis.insert(nkey);
                                    col_ma[nkey] = 1 - col_ma[x * m + y];
                                    q.emplace(nx, ny);
                                } else {
                                    if (col_ma[nkey] == col_ma[x * m + y]) {
                                        is_bipartite = false;
                                    }
                                }
                            }
                        }
                    }

                    int cimp;
                    if (comp == 1) {
                        cimp = 1;
                    } else {
                        cimp = is_bipartite ? 2 : 3;
                    }

                    col = max(col, cimp);
                }
            }

            sum += col;
            MA = max(MA, col);
        }

        cout << sum - MA << '\n';
    }

    return 0;
}
