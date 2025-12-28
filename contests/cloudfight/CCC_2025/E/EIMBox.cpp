#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x, y, time_limit;
    long long w, z;
    char comma;
    // read first line: x,y time_limit
    if (!(cin >> x)) return 0;
    cin >> comma >> y >> time_limit;
    // second line: w,z
    cin >> w >> comma >> z;

    // ---------- choose a safe Y ----------
    long long Ysafe = (abs(z) > 5) ? 10 : -10;   // any value with |Ysafe - z| > 2.5

    vector<int> xs, ys;
    long long curX = 0, curY = 0;

    // 1) move vertically to Ysafe
    while (curY != Ysafe) {
        int step = (Ysafe > curY) ? 1 : -1;
        xs.push_back(0);
        ys.push_back(step);
        curY += step;
    }

    // 2) move horizontally to x
    while (curX != x) {
        int step = (x > curX) ? 1 : -1;
        xs.push_back(step);
        ys.push_back(0);
        curX += step;
    }

    // 3) move vertically to y
    while (curY != y) {
        int step = (y > curY) ? 1 : -1;
        xs.push_back(0);
        ys.push_back(step);
        curY += step;
    }

    // pad to equal length
    size_t L = max(xs.size(), ys.size());
    xs.resize(L, 0);
    ys.resize(L, 0);

    // output
    for (size_t i = 0; i < L; ++i) {
        if (i) cout << ' ';
        cout << xs[i];
    }
    cout << "\n";
    for (size_t i = 0; i < L; ++i) {
        if (i) cout << ' ';
        cout << ys[i];
    }
    cout << "\n";
    return 0;
}
