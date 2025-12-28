#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

constexpr int inf = 1E9 + 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int ans = 0;
    
    std::multiset<int> S;
    
    std::vector<std::array<int, 3>> val;
    
    for (int i = 0; i < n; i++) {
        int k, l, r;
        std::cin >> k >> l >> r;
        
        int sum = 0;
        std::vector<int> a(k);
        for (int j = 0; j < k; j++) {
            std::cin >> a[j];
            sum += a[j];
        }
        
        S.insert(l);
        int pre = 0;
        for (int j = 0; j < k; j++) {
            val.push_back({r - (sum - pre), l + pre, l + pre + a[j]});
            pre += a[j];
        }
        val.push_back({r, l + sum, inf});
    }
    
    std::sort(val.begin(), val.end());
    
    for (auto [r, l1, l2] : val) {
        ans = std::max(ans, r - *S.rbegin());
        S.extract(l1);
        S.insert(l2);
    }
    std::cout << ans << "\n";
    
    return 0;
}

