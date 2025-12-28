#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<i64, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        a.emplace_back(x, i);
        a.emplace_back(y, i + n);
    }
    std::sort(a.begin(), a.end());
    
    i64 ans = 0;
    
    {
        i64 sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum -= 2 * a[i].first;
        }
        for (int i = n; i < 2 * n; i++) {
            sum += 2 * a[i].first;
        }
        int i = n;
        while (i < 2 * n && a[i].second < n) {
            i++;
        }
        
        if (i < 2 * n) {
            int cntl = 0;
            for (int i = 0; i < n - 1; i++) {
                cntl += (a[i].second >= n);
            }
            if (a[i].second != a[n - 1].second + n || cntl || n == 1) {
                ans = std::max(ans, sum - a[i].first);
            } else {
                ans = std::max(ans, sum - a[i].first + 2 * (a[n - 2].first - a[n - 1].first));
                ans = std::max(ans, sum - a[i + 1].first);
            }
        } else {
            ans = std::max(ans, sum - 2 * a[n].first + a[n - 1].first);
        }
    }
    
    {
        i64 sum = 0;
        for (int i = 0; i < n; i++) {
            sum -= 2 * a[i].first;
        }
        for (int i = n; i < 2 * n; i++) {
            sum += 2 * a[i].first;
        }
        int i = n - 1;
        while (i >= 0 && a[i].second < n) {
            i--;
        }
        
        if (i >= 0) {
            ans = std::max(ans, sum + a[i].first);
        } else {
            ans = std::max(ans, sum + 4 * a[n - 1].first - 3 * a[n].first);
        }
    }
    
    ans--;
    std::cout << ans << "\n";
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

