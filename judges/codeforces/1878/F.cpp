#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

ll dN(map<ll,ll>& m, ll n){
    for(int i = 2; i <= n*n; i++){
        while(n%i == 0){
            if(m.find(i) == m.end())m[i] += 2;
            else m[i]++;
            n /= i;
        }
    }
    ll sum = 1;
    for(auto& [num,val] : m){
        sum *= val;
    }
    return sum;
}

bool compare(map<ll,ll>& n, map<ll,ll> dn){
    bool ok = true;
    for(auto& [key,value] : dn){
        if(value > n[key]) ok = false;
    }
    return ok;
}

void solve(){
    ll x,k,dn,N,n,q; cin >> N >> q;
    map<ll,ll> M,m;
    dn = dN(M,N);
    n = N;m = M;
    for(int i = 0; i < q; i++){
        cin >> k;
        if(k == 1){
            cin >> x;
            dn = dN(m,x);
            map<ll,ll> dm;
            dN(dm,dn);
            bool ok = compare(m,dm);
            if(ok)cout << "YES\n";
            else cout << "NO\n";
        }else{
            m = M;n = N;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}