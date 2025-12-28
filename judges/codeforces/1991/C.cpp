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

void solve(){
    int n; cin >> n; vi arr(n); cin >> arr;
    for(int i = 1; i < n; i++) if((arr[i]%2) != (arr[i-1]%2)) {cout << "-1\n"; return;}

    for(int i = 0; i < n; i++){
     
    }

    sort(arr); vi sol, ar; ar.push_back(arr[0]);
    for(int i = 1; i < n; i++) if(arr[i] != ar[ar.size()-1]) ar.push_back(arr[i]);

    for(int i = 0; i < ar.size()-1 && sol.size() <= 40; i++){
        sol.push_back((ar[i+1]-ar[i])/2 + ar[i]);
        for(int j = 0; j < ar.size(); j++)
            ar[j] = abs(ar[j]-sol[sol.size()-1]);
    }
    if(ar[0] != 0) sol.push_back(ar[0]);
    if(sol.size() > 40) {cout << "-1\n"; return;}
    cout << sol.size() << "\n"; cout << sol << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << log2(200000) << endl;
    int t; cin >> t; while(t--)solve();
}