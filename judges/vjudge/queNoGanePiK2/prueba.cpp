#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define mp make_pair
#define sort(x) sort(x.begin(), x.end())
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.first >> p.second; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.first << " " << p.second; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}
/*
(CRT) - O(2n)

x === a_1 mod m_1
...
x === a_n mod m_n

parameters
vector<{a_i,m:i}> congruences
*/
//Efficient way to calculate powers
long long chinese_remainder_theorem(vector<pair<ll,ll> > const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.second;
    }
    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.first;
        long long M_i = M / congruence.second;
        long long N_i = mod_inv(M_i, congruence.second);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}
ll lucas(ll n, ll k, ll mod, vector<long long>& fact){
    if(n<k) return 0;
    if(n>=mod) return (lucas(n%mod, k%mod,mod,fact) * lucas(n/mod, k/mod,mod,fact)) % mod;  
    return (((fact[n]*mod_inv(fact[k],mod))%mod * mod_inv(fact[n-k],mod)))%mod;
}

void solve(){
    ll n,r,m; cin >> n >> r >> m;
    vector<ll> fact(50); fact[0] = 1;
    for(int i = 1; i <= 50; i++) fact[i] = (fact[i-1]*i)%m;
    vector<pair<ll,ll> > congruences;
    for(int i = 2; i < 50 && m != 1; i++){
        if(m%i == 0){
            congruences.push_back(mp(lucas(n,r,i,fact),i));
            m /= i;
        }
    }
    cout << chinese_remainder_theorem(congruences) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}
