#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)x.size())
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
const int mod = 1e9 + 7;
ll o = 0;
bool solve(ifstream& f, ofstream& of) {
    cout << ++o << endl;
    int n;
    f >> n;
    if (n == 0) {
        return false;
    }
    vll disp(n + 1), ans(n + 1);
    vi btlncks; btlncks.push_back(0);
    ll aans = 0;
    disp[0] = -1;
    for (int i = 1; i <= n; ++i) {
        f >> disp[i];
        while (disp[btlncks[sz(btlncks) - 1]] >= disp[i]) {
            btlncks.pop_back();
        }
        btlncks.push_back(i);
        if (disp[i] < 2) continue;
        ans[i] = ((disp[i] - 1) * (i - btlncks[sz(btlncks) - 2] - 1))%mod;
        ans[i] = (ans[i] + ans[btlncks[sz(btlncks) - 2]])%mod;
        if (disp[btlncks[sz(btlncks) - 2]] > 0) ans[i] = (ans[i] + disp[btlncks[sz(btlncks) - 2]] - 1)%mod;
        aans = (aans + ans[i])%mod;
    }
    of << aans << "\n";
    return true;
}

int main() {
    ifstream f; f.open("casesA.txt");
    ofstream of; of.open("resA.txt");
    
    while (solve(f,of));

    f.close(); of.close();
}