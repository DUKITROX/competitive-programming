#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define mp make_pair
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
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << "(" << p.first << " " << p.second << ")"; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

struct cmp{
    bool operator()(ii p1, ii p2){
        return (p1.first - p1.second < p2.first - p2.second);
    }
};

void solve(){
    int n,m; cin >> n >> m; vii ar(n),arr;

    for(int i = 0; i < n; i++) cin >> ar[i].first;
    for(int i = 0; i < n; i++) cin >> ar[i].second;
    sort(ar.begin(), ar.end(), cmp());
    arr.push_back(ar[0]);
    for(int i = 1; i < n; i++) if(ar[i].first < arr[arr.size()-1].first) arr.push_back(ar[i]);

    vector<ll> dp(arr[0].first+1,0);
    int j = arr.size()-1;
    for(int i = arr[arr.size()-1].first; i <= arr[0].first; i++){
        while(j > 0 && arr[j-1].first <= i)j--;
        int cant = (i - arr[j].first)/(arr[j].first - arr[j].second) + 1;
        dp[i] = cant<<1 + dp[i-cant*(arr[j].first - arr[j].second)];
    }
    ll cont = 0,c;
    for(int i = 0; i < m; i++){
        cin >> c;
        if(c >= arr[0].first){
            int cant = (c - arr[0].first)/(arr[0].first - arr[0].second) + 1;
            cont += (cant<<1) + dp[c-cant*(arr[0].first - arr[0].second)];
        }else cont += dp[c];
    }
    
    cout << cont << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}