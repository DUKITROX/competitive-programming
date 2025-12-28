#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll forward(int x, int y, int n) {
    ll d = 0;
    x--; y--; 
    for (int level = n; level >= 1; level--) {
        int h = 1 << (level - 1);
        int quad;
        if (x < h && y < h) {
            quad = 0;
        } else if (x >= h && y >= h) {
            quad = 1;
            x -= h;
            y -= h;
        } else if (x >= h && y < h) {
            quad = 2;
            x -= h;
        } else {
            quad = 3;
            y -= h;
        }
        d += (ll)quad * h * h;
    }
    if (x == 0 && y == 0) d += 1;
    else if (x == 1 && y == 1) d += 2;
    else if (x == 1 && y == 0) d += 3;
    else d += 4;
    return d;
}

pair<int, int> inverse(ll d, int n) {
    d--; 
    int x = 0, y = 0;
    for (int level = n; level >= 1; level--) {
        int h = 1 << (level - 1);
        ll quadrant_size = (ll)h * h;
        int quad = d / quadrant_size;
        d %= quadrant_size;
        int x_bit, y_bit;
        if (quad == 0) {
            x_bit = 0;
            y_bit = 0;
        } else if (quad == 1) {
            x_bit = 1;
            y_bit = 1;
        } else if (quad == 2) {
            x_bit = 1;
            y_bit = 0;
        } else {
            x_bit = 0;
            y_bit = 1;
        }
        x = (x << 1) | x_bit;
        y = (y << 1) | y_bit;
    }
    return {x + 1, y + 1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        while (q--) {
            string type;
            cin >> type;
            if (type == "->") {
                int x, y;
                cin >> x >> y;
                cout << forward(x, y, n) << '\n';
            } else {
                ll d;
                cin >> d;
                auto [x, y] = inverse(d, n);
                cout << x << ' ' << y << '\n';
            }
        }
    }
}
