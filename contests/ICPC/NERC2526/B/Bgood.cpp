#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        b.push(x);
    }
    
    int t = 0;
    while (!a.empty() && !b.empty()) {
        int x = a.top();
        int y = b.top();
        b.pop();
        if (y > x) {
            b.push(y - x);
        }
        std::swap(a, b);
        t ^= 1;
    }
    if (t == 1) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
    }
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

