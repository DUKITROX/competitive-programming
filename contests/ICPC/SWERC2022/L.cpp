#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
using ll = long long int;


void solve(){
    ll n;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    ll q;
    cin >> q;

    vector<pair<ll,ll> > cont(q);
    for (int i = 0; i < q; i++) {
        cin >> cont[i].first >> cont[i].second;
    }

    ll p = 0;
    for (char c : line)
        if (c == '+')
            p++;

    ll m = n - p;

    for (int i = 0; i < q; i++){
        ll a = max(cont[i].first, cont[i].second);
        ll b = min(cont[i].first, cont[i].second);

        if (a != b) {
            ll phi = b * (m-p) / (a-b);
            ll inf = max(-phi, 0LL);
            ll sup = min(p-phi, n);
            if (b * (m-p) % (a-b) == 0 && sup - inf >= 0)
                cout << "YES";
            else
                cout << "NO";
        }
        else {
            if(m - p == 0) cout << "YES";
            else cout << "NO";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
