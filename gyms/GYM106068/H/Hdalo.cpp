#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = ((unsigned int)-1)>>1;

#if defined(LOCAL) || defined(CPPM)
#define flog(...) cout.flush(), fprintf(stderr, __VA_ARGS__)
#else
#define flog(...) 0
#endif
int _d = 0;
#define flogrec(n, ...) flog(string(2*(n), ' ').c_str()), flog(__VA_ARGS__)

#define TT template<typename T>
TT using V = vector<T>; TT using VV = V<V<T>>; TT using VVV = V<VV<T>>;
TT ostream& operator<<(ostream &os, const V<T> &v) { for (int i = 0; i < v.size(); i++) os << (i ? " " : "") << v[i]; return os; }
TT istream& operator>>(istream &is, V<T> &v) { for (auto &a : v) is >> a; return is; }
#define VVVT(T, n) using v##n = V<T>; using vv##n = V<v##n>; using vvv##n = V<vv##n>
using pii = pair<int, int>; VVVT(int, i); VVVT(char, c); VVVT(pii, pii); VVVT(string, s);

const int N = 1e5+5, M = 1e9+5, Mrt3 = 1e3+5;

inline int log2(int n) { return 63-__builtin_clzll(n); }

inline int pow(int a, int b) {
    int r = 1;
    for (int i = 0; i < b; i++) r *= a;
    return r;
}

inline int nroot(int k, int n) {
    if (k < 1 || k%2 == 0 && n < 0)
        return -1;
    if (n < 0) return -nroot(k, -n);

    int r = 0;
    for (int i = log2(n)/k, b = 1ll<<i; i >= 0; i--, b >>= 1) {
        int c = r|b;
        if (pow(c, k) <= n)
            r = c;
    }
    return r;
}

inline int r3u(int n) { return nroot(3, n-1)+1; }

template<typename T> struct Min {
    T id = {INF, INF};
    T operator()(T x, T y) { return min(x, y); }
    T rep(T x, int c) { return x; }
};

template<typename T> struct Max {
    T id = -INF;
    T operator()(T x, T y) { return max(x, y); }
    T rep(T x, int c) { return x; }
};

template<typename T, typename F> struct SegmentTree {
    F f; int n; vector<T> st;
    SegmentTree(const vector<T> &v) : n(v.size()), st(2*n) {
        for (int i = 0; i < n; i++) st[i+n] = v[i];
        for (int i = n-1; i >= 0; i--) st[i] = f(st[2*i], st[2*i+1]);
    }

    T query(int l, int r) {
        T rl = f.id, rr = f.id;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l%2 == 1) rl = f(rl, st[l++]);
            if (r%2 == 0) rr = f(st[r--], rr);
        }
        return f(rl, rr);
    }
    void set(int i, T v) {
        i += n; st[i] = v;
        for (i /= 2; i > 0; i /= 2)
            st[i] = f(st[i*2], st[i*2+1]);
    }

    T get(int i) { return query(i, i); }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vi v(n), v2(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = i-r3u(a);
        v2[n-i-1] = (n-i-1)-r3u(a);
    }
    for (auto a : v) flog("%d ", a); flog("\n");
    for (auto a : v2) flog("%d ", a); flog("\n");

    SegmentTree<int, Max<int>> st(v);
    SegmentTree<int, Max<int>> st2(v2);

    int q;
    cin >> q;
    while (q--) {
        flog("\n");

        int o;
        cin >> o;
        if (o == 1) {
            int i, v;
            cin >> i >> v; i--;
            flog("v[%d] = %d\n", i, v);
            st.set(i, i-r3u(v));
            st2.set(n-i-1, n-i-1-r3u(v));
        }else {
            int i;
            cin >> i; i--;
            flog("? %d\n", i);

            int u = 1;
            flog("u: %d %d\n", u, st.st[u]);
            while (u < n && st.st[u] >= i) {
                if (st.st[2*u] >= i)
                    u = 2*u;
                else
                    u = 2*u+1;
                flog("u: %d %d\n", u, st.st[u]);
            }
            
            int j = u-n;
            if (st.st[u] >= i) {
                cout << j+1 << "\n";
                continue;
            }
            flog("rev\n");

            u = 1;
            flog("u: %d %d\n", u, st2.st[u]);
            while (u < n && st2.st[u] >= n-i-1) {
                if (st2.st[2*u] >= n-i-1)
                    u = 2*u;
                else
                    u = 2*u+1;
                flog("u: %d %d\n", u, st2.st[u]);
            }

            j = n-(u-n)-1;
            if (st2.st[u] >= n-i-1)
                cout << j+1 << "\n";
            else
                cout << -1 << "\n";
        }
    }
}


