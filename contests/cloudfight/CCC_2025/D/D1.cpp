#include <bits/stdc++.h>
using namespace std;

void printSeq(int pos) {
    cout << "0 ";

    int k = abs(pos);
    int s = (pos > 0 ? 1 : -1);

    if (k < 8) {
        vector<int> v(k);

        // Build symmetric ramp of length k
        // 5 4 3 4 5  for k=5
        for (int i = 0; i < k; i++) {
            int dist = abs(i - (k - 1) / 2);
            v[i] = s * (5 - dist);
        }

        for (int x : v) cout << x << " ";
    }
    else {
        int act = 5 * s;
        for (int i = 0; i < 4; i++) {
            cout << act << " ";
            act += -s;
        }
        for (int i = 0; i < k - 8; i++) {
            cout << act << " ";
        }
        act -= -s;
        for (int i = 0; i < 4; i++) {
            cout << act << " ";
            act -= -s;
        }
    }

    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    while (N--) {
        char c;
        int pos1, pos2, time;
        cin >> pos1 >> c >> pos2 >> time;

        printSeq(pos1);
        printSeq(pos2);
    }
}

