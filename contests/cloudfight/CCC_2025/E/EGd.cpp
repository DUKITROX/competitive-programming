#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
Movement rules enforced:
- Lists start with 0 and end with 0.
- From 0 -> {-5,0,5}. From 5 -> {4,5,0}. From -5 -> {-4,-5,0}.
- From k in {1,2,3,4} -> {k-1,k,k+1}; similarly for negatives.
- Each nonzero item moves exactly 1 unit on that axis and costs |v| time.
- Zeros cost 1 time unit and don't move.
We synchronize time by moving one axis at a time and padding the other with zeros.
Collision: forbidden square [w-2,w+2] x [z-2,z+2] (inclusive).
*/

static inline bool inRange(ll v, ll lo, ll hi) {
    if (lo > hi) swap(lo, hi);
    return lo <= v && v <= hi;
}

struct Builder {
    // Output sequences for x and y
    vector<int> X, Y;

    // Build absolute-value sequence of length D (D>=1) that
    // starts at 5 and ends at 5, uses steps of size at most 1,
    // and never touches 0. This matches the per-step rule.
    // For D<=9 we make a "cap" between 5 and some L.
    // For D>=10 we use a 1-plateau in the middle.
    static vector<int> absSeq(long long D) {
        vector<int> s;
        if (D <= 0) return s;
        if (D <= 9) {
            int down_len = int((D + 1) / 2);       // ceil(D/2)
            int L = 5 - (down_len - 1);            // valley
            // Descend 5 -> L
            for (int v = 5; v >= L; --v) s.push_back(v);
            int up_len = int(D) - down_len;
            if (D % 2 == 0) {
                // even: duplicate valley
                for (int v = L; v <= 5; ++v) s.push_back(v);
            } else {
                // odd: valley appears once
                for (int v = L + 1; v <= 5; ++v) s.push_back(v);
            }
        } else {
            // D >= 10: go 5,4,3,2,1, (repeat 1), 2,3,4,5
            long long k1 = D - 9; // how many 1's to repeat in the middle
            s = {5,4,3,2,1};
            for (ll i = 0; i < k1; ++i) s.push_back(1);
            s.push_back(2); s.push_back(3); s.push_back(4); s.push_back(5);
        }
        return s;
    }

    // Append one x step of signed value 'vx' and pad y with |vx| zeros (time sync).
    void pushXStep(int vx) {
        X.push_back(vx);
        int t = (vx == 0) ? 1 : abs(vx);
        for (int i = 0; i < t; ++i) Y.push_back(0);
    }
    // Append one y step of signed value 'vy' and pad x with |vy| zeros (time sync).
    void pushYStep(int vy) {
        Y.push_back(vy);
        int t = (vy == 0) ? 1 : abs(vy);
        for (int i = 0; i < t; ++i) X.push_back(0);
    }

    // Move |D| units along X with sign sgn (+1 or -1); Y idles the right total time.
    void moveX(long long D, int sgn) {
        if (D <= 0) return;
        auto seq = absSeq(D);
        for (int a : seq) pushXStep(sgn * a);
    }
    // Move |D| units along Y with sign sgn; X idles.
    void moveY(long long D, int sgn) {
        if (D <= 0) return;
        auto seq = absSeq(D);
        for (int a : seq) pushYStep(sgn * a);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    string line;

    for (int tc = 0; tc < T; ++tc) {
        // Read "x,y time_limit"
        string l1;
        if (cin.peek() == '\n') cin.get();
        do { if (!getline(cin, l1)) return 0; } while (l1.empty());
        for (char &c : l1) if (c == ',') c = ' ';
        ll x, y, tlim;
        {
            stringstream ss(l1);
            ss >> x >> y >> tlim;
        }
        // Read "w,z"
        string l2;
        do { if (!getline(cin, l2)) return 0; } while (l2.empty());
        for (char &c : l2) if (c == ',') c = ' ';
        ll w, z;
        {
            stringstream ss(l2);
            ss >> w >> z;
        }

        ll xlo = w - 2, xhi = w + 2;
        ll ylo = z - 2, yhi = z + 2;

        auto inXBand = [&](ll X) { return inRange(X, xlo, xhi); };
        auto inYBand = [&](ll Y) { return inRange(Y, ylo, yhi); };
        auto inSquare = [&](ll X, ll Y) { return inXBand(X) && inYBand(Y); };

        // If start or target is inside the 5x5 forbidden square, it's impossible.
        if (inSquare(0,0) || inSquare(x,y)) {
            cout << "IMPOSSIBLE\n";
            cout << "IMPOSSIBLE\n";
            continue;
        }

        Builder b;
        // Start with a 0 on both axes (costs 1 time unit)
        b.X.push_back(0);
        b.Y.push_back(0);

        ll cx = 0, cy = 0;

        auto go_x = [&](ll to) {
            int sgn = (to >= cx) ? +1 : -1;
            b.moveX(llabs(to - cx), sgn);
            cx = to;
        };
        auto go_y = [&](ll to) {
            int sgn = (to >= cy) ? +1 : -1;
            b.moveY(llabs(to - cy), sgn);
            cy = to;
        };

        // Plan a safe axis-only path that stays outside the 5x5 square.
        // If y=0 is safe, go horizontal first; otherwise go vertical first.
        bool ok = true;
        if (!inYBand(0)) {
            // y=0 safe → X first
            go_x(x); // (cx, cy) = (x, 0)
            if (inXBand(cx)) {
                // Detour horizontally to a safe x, do Y, then return to x.
                ll xsafe = (cx <= w) ? (w - 3) : (w + 3);
                go_x(xsafe);                // still at y=0 (safe since y=0 outside y band)
                go_y(y);                    // at x=xsafe (safe since xsafe outside x band)
                if (inYBand(cy)) ok = false; // would imply target inside square (caught earlier)
                if (ok) go_x(x);            // finish at (x, y)
            } else {
                go_y(y);
            }
        } else {
            // y=0 unsafe → Y first (x=0 must be outside or start would be inside)
            if (inXBand(0)) ok = false;
            if (ok) {
                if (inYBand(y)) {
                    // Move to a safe y first, then X, then finish Y.
                    ll ysafe = (y <= z) ? (z - 3) : (z + 3);
                    go_y(ysafe);            // x=0 outside x band, so vertical is safe
                    go_x(x);                // at y=ysafe (safe since ysafe outside y band)
                    if (inXBand(cx)) ok = false; // would imply target inside square
                    if (ok) go_y(y);
                } else {
                    go_y(y);
                    go_x(x);
                }
            }
        }

        // Close with a final 0 on both axes (costs 1 time unit)
        if (ok) {
            b.X.push_back(0);
            b.Y.push_back(0);

            // Sanity: both axes should represent the same total time.
            auto totalTime = [&](const vector<int>& v) {
                long long t = 0;
                for (int a : v) t += (a == 0 ? 1 : abs(a));
                return t;
            };
            long long TX = totalTime(b.X), TY = totalTime(b.Y);
            if (TX != TY) ok = false;
            if (ok && TX > tlim) ok = false;
        }

        if (!ok) {
            cout << "IMPOSSIBLE\n";
            cout << "IMPOSSIBLE\n";
            continue;
        }

        // Output: two lines per test, NO extra blank line between cases.
        for (size_t i = 0; i < b.X.size(); ++i) {
            if (i) cout << ' ';
            cout << b.X[i];
        }
        cout << "\n";
        for (size_t i = 0; i < b.Y.size(); ++i) {
            if (i) cout << ' ';
            cout << b.Y[i];
        }
        cout << "\n";
    }
    return 0;
}

