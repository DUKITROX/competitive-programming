#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define f first
#define s second
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
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.f >> p.s; return is;};
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.f << " " << p.s; return os;};
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}

int memo[5000][5000] = {0};

void solve(){
    int n, sol = INF; cin >> n; vi arr(n); cin >> arr;
    memset(memo,0,sizeof memo);
    for(int i = 0; i < 5000; i++) memo[0][i] = abs(arr[0]-i);
    for(int k = 1; k < n; k++){
        int po = memo[k-1][0];
        for(int i = 0; i < 5000; i++){
            memo[k][i] = abs(arr[k] - i) + po;
            po = min(po, memo[k][i]);
            if(k == n-1) sol = min(sol, memo[k][i]);
        }
    }
    cout << (n == 1 ? 0 : sol) << "\n";
}
/*
3
1
1

2
3 1

3
4 2 4

0 2 2
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}