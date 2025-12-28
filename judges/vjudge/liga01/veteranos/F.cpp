#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    vector<string> arr(8);
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    bool p = true;
    vector<bool> col(8, false), fil(8, false), d1(20, false), d2(20, false);
    int cont = 0;
    for (int i = 0; i < 8; i++) { // fil
        for (int j = 0; j < 8; j++) { // col
            if (arr[i][j] == '*') {
                cont++;
                if (fil[i] || col[j] || d1[i + j] || d2[i - j + 8]) {
                    p = false;
                }
                fil[i] = col[j] = d1[i + j] = d2[i - j + 8] = true;
            }
        }
    }

    cout << (p && cont==8 ? "valid" : "invalid") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}