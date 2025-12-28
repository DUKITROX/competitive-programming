#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::array<i64, 26>> cnt(n);
    std::array<i64, 26> tot {};
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (auto c : s) {
            cnt[i][c - 'A']++;
            tot[c - 'A']++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        auto have = tot;
        for (int c = 0; c < 26; c++) {
            have[c] -= cnt[i][c];
            have[c] *= m;
            have[c] -= cnt[i][c];
        }
        auto need = tot;
        i64 ans = 1E18;
        for (auto c = 0; c < 26; c++) {
            need[c] -= cnt[i][c];
            if (have[c] < 0) {
                ans = -1;
                break;
            }
            if (need[c]) {
                ans = std::min(ans, have[c] / need[c]);
            }
        }
        std::cout << ans << " \n"[i == n - 1];
    }
    
    return 0;
}

