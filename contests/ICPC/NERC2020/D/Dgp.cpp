#include <bits/stdc++.h>
using namespace std;

// A node in the back‐pointer chain:
struct Node {
    int idx;        // index of the card we just used
    int prevDigit;  // the previous DP state digit (–1 if starting here)
    Node* prev;     // link to the previous node in the chain

    Node(int _idx, int _prevDigit, Node* _prev)
     : idx(_idx), prevDigit(_prevDigit), prev(_prev) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    const long double NEG_INF = numeric_limits<long double>::lowest();
    // dp[r] = best log-sum for subsets whose product mod 10 == r
    vector<long double> dp(10, NEG_INF), dp_prev(10);
    // chain[r] = pointer to the last node of the best subset for dp[r]
    vector<Node*> chain(10, nullptr), chain_prev(10);

    for(int i = 0; i < n; i++){
        int last = a[i] % 10;
        long double lg = logl((long double)a[i]);

        // snapshot previous state
        dp_prev = dp;
        chain_prev = chain;

        // Case #1: take the single element subset {a[i]}
        if (lg > dp[last]) {
            dp[last] = lg;
            chain[last] = new Node(i, -1, nullptr);
        }

        // Case #2: extend any previous subset
        for(int r = 0; r < 10; r++){
            if (chain_prev[r] == nullptr) continue;
            int nd = (r * last) % 10;
            long double cand = dp_prev[r] + lg;
            if (cand > dp[nd]){
                dp[nd] = cand;
                chain[nd] = new Node(i, r, chain_prev[r]);
            }
        }
    }

    // If there's no way to get digit d, fail
    if (chain[d] == nullptr){
        cout << -1 << "\n";
        return 0;
    }

    // Reconstruct the chosen subset by following back‐pointers
    vector<int> chosen;
    Node* cur = chain[d];
    while(cur){
        chosen.push_back(cur->idx);
        cur = cur->prev;
    }
    // The chain was followed from last to first; reverse it
    reverse(chosen.begin(), chosen.end());

    // Output
    cout << chosen.size() << "\n";
    for(int idx : chosen){
        cout << a[idx] << " ";
    }
    cout << "\n";
    return 0;
}

