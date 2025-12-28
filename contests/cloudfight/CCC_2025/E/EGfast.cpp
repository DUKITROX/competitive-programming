#include <bits/stdc++.h>
using namespace std;

// Build a valid sequence that produces exactly 'dist' net displacement.
// Uses allowed transitions: 0<->±5, then ±5<->±4<->...<->±1
vector<int> build(int dist) {
    vector<int> seq;
    seq.push_back(0); // must start at 0

    if (dist == 0) {
        seq.push_back(0);
        return seq;
    }

    int sgn = (dist > 0 ? 1 : -1);
    int d = abs(dist);

    // Ramp: 0 -> ±5 -> ±4 -> ±3 -> ±2 -> ±1
    seq.push_back(5 * sgn);
    seq.push_back(4 * sgn);
    seq.push_back(3 * sgn);
    seq.push_back(2 * sgn);
    seq.push_back(1 * sgn);

    d -= (5 + 4 + 3 + 2 + 1); // subtract ramp distance

    // Cruise at speed ±1 for remaining distance
    while (d > 0) {
        seq.push_back(1 * sgn);
        d--;
    }

    // Ramp down: ±1 -> ±2 -> ±3 -> ±4 -> ±5 -> 0
    seq.push_back(2 * sgn);
    seq.push_back(3 * sgn);
    seq.push_back(4 * sgn);
    seq.push_back(5 * sgn);
    seq.push_back(0);

    return seq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int x, y, w, z, time_limit;
        char c;
        cin >> x >> c >> y >> time_limit;
        cin >> w >> c >> z;

        // Large safe detour height
        int H = 200; // big enough that asteroid never interferes

        // Build moves:
        vector<int> up    = build(H);
        vector<int> horiz = build(x);
        vector<int> down  = build(y - H);

        vector<int> xs, ys;

        // Phase 1: go up
        for (int v : up) { xs.push_back(0); ys.push_back(v); }

        // Phase 2: horizontal
        for (int v : horiz) { xs.push_back(v); ys.push_back(0); }

        // Phase 3: down
        for (int v : down) { xs.push_back(0); ys.push_back(v); }

        // Output
        for (int i = 0; i < xs.size(); i++)
            cout << xs[i] << (i+1 == xs.size() ? '\n' : ' ');
        for (int i = 0; i < ys.size(); i++)
            cout << ys[i] << (i+1 == ys.size() ? '\n' : ' ');
    }
}

