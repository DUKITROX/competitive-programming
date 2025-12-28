#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define f first
#define s second
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

void solve(){
    int n,m; cin >> n >> m; vi a(n),b(n); cin >> a >> b;
    sort(b.begin(), b.end(), greater<int>());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}