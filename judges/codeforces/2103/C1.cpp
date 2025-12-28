#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt; while (tt--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        if (n == 3) {
            int cnt = 0;
            for (int i = 1; i <= 3; i++)
                if (a[i] <= k) cnt++;
            cout << (cnt >= 2 ? "YES\n" : "NO\n");
            continue;
        }

        auto good = [&](int i){
            return (a[i] <= k || a[i+1] <= k);
        };

        bool ok = false;
        if (good(1) && n >= 4 && good(3)) {
            ok = true;
        }
        if (good(1) && good(n-1)) {
            ok = true;
        }
        if (n >= 4 && good(n-3) && good(n-1)) {
            ok = true;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}

