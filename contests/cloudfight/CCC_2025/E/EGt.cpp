#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
    int sx, sy; // signs in {-1,0,1}
};

pair<int,int> parse_pair(const string &s) {
    int c = (int)s.find(',');
    int a = stoi(s.substr(0, c));
    int b = stoi(s.substr(c + 1));
    return {a, b};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        string sxy, swz;
        long long time_limit;
        cin >> sxy >> time_limit;
        cin >> swz;

        auto [tx, ty] = parse_pair(sxy);
        auto [wx, wy] = parse_pair(swz);

        auto inside = [&](int x, int y) -> bool {
            return (abs(x - wx) <= 2 && abs(y - wy) <= 2);
        };

        // Trivial case: already at target
        if (tx == 0 && ty == 0) {
            cout << "0\n0\n";
            if (T) cout << "\n";
            continue;
        }

        // Bound search box using time_limit and positions
        int L = (int)time_limit;
        const int EXTRA = 6;

        long long minXll = min({0, tx, wx}) - EXTRA;
        long long maxXll = max({0, tx, wx}) + EXTRA;
        long long minYll = min({0, ty, wy}) - EXTRA;
        long long maxYll = max({0, ty, wy}) + EXTRA;

        minXll = max(minXll, -(long long)L - 5);
        maxXll = min(maxXll, (long long)L + 5);
        minYll = max(minYll, -(long long)L - 5);
        maxYll = min(maxYll, (long long)L + 5);

        int minX = (int)minXll, maxX = (int)maxXll;
        int minY = (int)minYll, maxY = (int)maxYll;

        int W = maxX - minX + 1;
        int H = maxY - minY + 1;

        auto inBox = [&](int x, int y) -> bool {
            return (x >= minX && x <= maxX && y >= minY && y <= maxY);
        };

        // If start is invalid (should not happen in proper tests), bail
        if (inside(0,0) || !inBox(0,0)) {
            cout << "0\n0\n";
            if (T) cout << "\n";
            continue;
        }

        // Encode state to index
        auto idx = [&](int x, int y, int sx, int sy) -> int {
            int ix = x - minX;
            int iy = y - minY;
            int isx = sx + 1; // -1,0,1 -> 0,1,2
            int isy = sy + 1;
            return (((ix * H + iy) * 3 + isx) * 3 + isy);
        };

        const int INF = 1e9;
        int totalStates = W * H * 9;

        vector<int> dist(totalStates, INF);
        vector<int> parent(totalStates, -1);
        vector<signed char> pvx(totalStates), pvy(totalStates);

        queue<State> q;
        State start{0, 0, 0, 0};
        int startId = idx(0, 0, 0, 0);
        dist[startId] = 0;
        q.push(start);

        int goalId = -1;
        bool found = false;

        while (!q.empty() && !found) {
            State cur = q.front();
            q.pop();

            int id0 = idx(cur.x, cur.y, cur.sx, cur.sy);
            int d = dist[id0];

            // We will later prepend one leading 0-step, so we need d + 1 <= time_limit
            if (d >= (int)time_limit - 1) continue;

            for (int nsx = -1; nsx <= 1; ++nsx) {
                if (abs(nsx - cur.sx) > 1) continue;
                for (int nsy = -1; nsy <= 1; ++nsy) {
                    if (abs(nsy - cur.sy) > 1) continue;

                    int nx = cur.x + nsx;
                    int ny = cur.y + nsy;

                    if (!inBox(nx, ny)) continue;
                    if (inside(nx, ny)) continue;

                    int id1 = idx(nx, ny, nsx, nsy);
                    if (dist[id1] <= d + 1) continue;

                    dist[id1] = d + 1;
                    parent[id1] = id0;
                    pvx[id1] = (signed char)nsx;
                    pvy[id1] = (signed char)nsy;
                    q.push({nx, ny, nsx, nsy});

                    // We only accept solutions that end with sx = sy = 0
                    if (nx == tx && ny == ty && nsx == 0 && nsy == 0) {
                        goalId = id1;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }

        if (goalId == -1) {
            // With the problem's promise (big time_limit, small movement),
            // this should not happen.
            cout << "0\n0\n";
            if (T) cout << "\n";
            continue;
        }

        // Reconstruct sign path
        vector<int> sx_path, sy_path;
        int cur = goalId;
        while (parent[cur] != -1) {
            sx_path.push_back(pvx[cur]);
            sy_path.push_back(pvy[cur]);
            cur = parent[cur];
        }
        reverse(sx_path.begin(), sx_path.end());
        reverse(sy_path.begin(), sy_path.end());

        // Build output lists; prepend leading 0 so lists start with 0
        vector<int> x_out, y_out;
        x_out.reserve(sx_path.size() + 1);
        y_out.reserve(sy_path.size() + 1);

        x_out.push_back(0);
        y_out.push_back(0);

        for (size_t i = 0; i < sx_path.size(); ++i) {
            int sx = sx_path[i];
            int sy = sy_path[i];
            x_out.push_back(sx == 0 ? 0 : (sx > 0 ? 5 : -5));
            y_out.push_back(sy == 0 ? 0 : (sy > 0 ? 5 : -5));
        }

        // Print
        for (size_t i = 0; i < x_out.size(); ++i) {
            if (i) cout << ' ';
            cout << x_out[i];
        }
        cout << "\n";
        for (size_t i = 0; i < y_out.size(); ++i) {
            if (i) cout << ' ';
            cout << y_out[i];
        }
        cout << "\n";

        if (T) cout << "\n";
    }

    return 0;
}

