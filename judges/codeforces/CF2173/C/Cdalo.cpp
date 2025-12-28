#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = 1e18;

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

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        vi v(n);
        cin >> v;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        n = v.size();

        vi res;
        vi used(n, false);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                int x = v[i];
                res.push_back(x);
                for (int j = 2*x; j <= k; j += x) {
                    auto it = lower_bound(v.begin(), v.end(), j);
                    if (it == v.end() || *it != j)
                        goto impossible;
                    used[it-v.begin()] = true;
                }
            }
        }
        cout << res.size() << "\n" << res << "\n";
        continue;
        impossible:
        cout << "-1\n";
    }
}
