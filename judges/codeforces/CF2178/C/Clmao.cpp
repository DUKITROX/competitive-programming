#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        long long S = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            S += a[i];
        }

        // Case U = 1 (child 1 remains unassigned)
        long long best = -S + a[1];

        long long sumPos = 0; // sum of positive a[i] for i in [2 .. current-1]
        for (int U = 2; U <= n; U++) {
            long long cand = -S + a[U] + 2LL * a[1] + 2LL * sumPos;
            best = max(best, cand);

            // After considering U, extend prefix for future U's
            if (a[U] > 0) sumPos += a[U];
        }

        cout << best << "\n";
    }
    return 0;
}

