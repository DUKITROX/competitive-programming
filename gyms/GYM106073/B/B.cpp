#include <bits/stdc++.h>
using namespace std;

#define int int64_t
typedef long long ll;

bool demais = false;

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    y -= a/b * x;
    return d;
}

pair<ll,ll> crt(ll a, ll m, ll b, ll n) {
    if (n > m) swap(a, b), swap(m, n);
    ll x, y;
    ll g = euclid(m, n, x, y);
    if ((a - b) % g != 0) return {0, -1}; 
    ll modn = n / g;
    ll t = ((b - a) / g % modn * x % modn + modn) % modn;
    ll res;
    if (t != 0 && m > LLONG_MAX / t) {demais = true;res = a % (m * modn); } else {res = (a + t * m) % (m * modn);}
    ll lcm = m / g * n;
    if (lcm > 1e18) lcm = 1e18; 
    if (res < 0) res += lcm;
    return {res, lcm};
}

pair<ll,ll> crt_system(const vector<ll>& a, const vector<ll>& m) {
    ll x = a[0];
    ll mod = m[0];
    if (x > 1000000000LL) demais = true;

    for (int i = 1; i < (int)a.size(); i++) {
        auto [cur, new_mod] = crt(x, mod, a[i], m[i]);
        if (new_mod == -1) return {0, -1}; // no solution
        x = cur;
        mod = new_mod;
        if (x > 1000000000LL) demais = true;
    }
    return {x, mod};
}

// ------------ KMP prefix function -----------------
vector<int> pi(const vector<int>& s) {
    vector<int> p(s.size());
    for (int i = 1; i < (int)s.size(); i++) {
        int g = p[i-1];
        while (g && s[i] != s[g]) g = p[g-1];
        p[i] = g + (s[i] == s[g]);
    }
    return p;
}

vector<int64_t> match(const vector<int>& s, const vector<int>& pat) {
    vector<int> pa(pat); pa.push_back(-1);
    for (auto e : s) pa.push_back(e);
    auto p = pi(pa);
    vector<int64_t> res;
    for (int i = (int)p.size() - (int)s.size(); i < (int)p.size(); i++)
        if (p[i] == (int)pat.size())
            res.push_back(i - 2 * (int)pat.size());
    return res;
}

// ------------ Main solve -----------------
void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n), p(n), v(n,0); 
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;

    vector<ll> A, M;
    for (int i = 0; i < n; i++) if (!v[i]) {
        vector<int> pos; pos.push_back(i);
        v[i] = 1;
        for (int act = p[i]; act != pos[0]; act = p[act])
            pos.push_back(act), v[act] = 1;

        vector<int> _b(pos.size()*2), _a(pos.size());
        for (int j = 0; j < (int)pos.size(); j++) {
            _b[j] = _b[j+pos.size()] = b[pos[j]];
            _a[j] = a[pos[j]];
        }
        _b.pop_back();
        auto res = match(_b, _a);

        if (res.empty()) {
            cout << "IMPOSSIVEL\n";
            return;
        } else {
            A.push_back(res[0]);
            if (res.size() == 1) M.push_back(pos.size());
            else M.push_back(abs(res[1] - res[0]));
        }
    }

    auto sol = crt_system(A, M);
    if (sol.second == -1) cout << "IMPOSSIVEL\n";
    else if (demais) cout << "DEMAIS\n";
    else cout << sol.first << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

