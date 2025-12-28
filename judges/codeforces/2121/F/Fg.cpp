#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Count subarrays of `v` whose sum == S.
ll count_sum_eq(const vector<ll> &v, ll S) {
    unordered_map<ll,int> freq;
    freq.reserve(v.size()*2);
    freq[0] = 1;
    ll pref = 0, cnt = 0;
    for (ll x : v) {
        pref += x;
        auto it = freq.find(pref - S);
        if (it != freq.end()) cnt += it->second;
        ++freq[pref];
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll S, X;
        cin >> n >> S >> X;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll answer = 0;
        int i = 0;
        // process each maximal segment where all a[i] <= X
        while (i < n) {
            if (a[i] > X) {
                ++i;
                continue;
            }
            int j = i;
            while (j < n && a[j] <= X) ++j;
            // segment is [i..j-1]
            vector<ll> seg(a.begin()+i, a.begin()+j);

            // 1) total subarrays in seg with sum == S
            ll total = count_sum_eq(seg, S);

            // 2) subtract those with no element == X
            ll withoutX = 0;
            int start = 0;
            for (int k = 0; k < (int)seg.size(); k++) {
                if (seg[k] == X) {
                    // process subarray seg[start..k-1]
                    if (k > start) {
                        vector<ll> sub(seg.begin()+start, seg.begin()+k);
                        withoutX += count_sum_eq(sub, S);
                    }
                    start = k+1;
                }
            }
            // tail after last X
            if (start < (int)seg.size()) {
                vector<ll> sub(seg.begin()+start, seg.end());
                withoutX += count_sum_eq(sub, S);
            }

            answer += (total - withoutX);
            i = j;
        }

        cout << answer << "\n";
    }
    return 0;
}

