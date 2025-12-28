#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

std::vector<std::vector<int>> S;

std::vector<int> A;

bool test = false;

int query(int p, int e) {
    if (test) {
        assert(p < S.size());
        S.push_back(S[p]);
        assert(std::find(S[p].begin(), S[p].end(), e) == S[p].end());
        S.back().push_back(e);
        std::set<int> c {0};
        for (auto x : S.back()) {
            if (c.contains(A[x])) {
                return 0;
            }
            c.insert(A[x]);
        }
        return 1;
    } else {
        std::cout << "? " << p << " " << e + 1 << std::endl;
        int ans;
        std::cin >> ans;
        return ans;
    }
}

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int m;
    if (test) {
        m = rng() % 100 + 1;
        A.clear();
        for (int i = 0; i < m; i++) {
            A.push_back(rng() % 7);
        }
        S = {{}};
    } else {
        std::cin >> m;
    }
    
    std::vector<int> bel(m), ans(m);
    int tot = 0;
    std::vector<int> s(16);
    
    for (int i = 0; i < m; i++) {
        int lo = 0, hi = 15;
        int val = -1;
        while (lo < hi) {
            int x = (lo + hi) / 2;
            tot++;
            if (query(x < 14 ? s[x] : 0, i)) {
                hi = x;
                val = tot;
            } else {
                lo = x + 1;
            }
        }
        if (val == -1) {
            bel[i] = -1;
            ans[i] = -1;
        } else {
            bel[i] = lo;
            if (lo == 14) {
                tot++;
                if (query(s[lo], i)) {
                    s[lo] = tot;
                }
            } else {
                s[lo] = val;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (ans[i] == -1) {
            continue;
        }
        int lo = bel[i], hi = 14;
        while (lo < hi) {
            int x = (lo + hi + 1) / 2;
            tot++;
            if (query(s[x], i)) {
                hi = x - 1;
            } else {
                lo = x;
            }
        }
        ans[i] = lo < 14 ? lo + 1 : 0;
    }
    
    assert(tot <= 8 * m);
    
    if (test) {
        for (int i = 0; i < m; i++) {
            if (A[i] == 0) {
                assert(ans[i] == -1);
            } else {
                int cnt = std::count(A.begin(), A.end(), A[i]);
                if (cnt <= 14) {
                    assert(ans[i] == cnt);
                } else {
                    assert(ans[i] == 0);
                }
            }
        }
    }
    
    std::cout << "!";
    for (auto x : ans) {
        std::cout << " " << x;
    }
    std::cout << std::endl;
    
    int ret;
    std::cin >> ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

