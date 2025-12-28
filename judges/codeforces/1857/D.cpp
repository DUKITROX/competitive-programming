#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

void solve(){
    int n; cin >> n; vi a(n),b(n),sol; cin >> a >> b;
    int M=-2*INF;
    for(int i = 0; i < n; i++) M = max(M, a[i]-b[i]);
    for(int i = 0; i < n; i++){
        if(a[i]-b[i] == M)sol.push_back(i+1);
    }
    cout << sol.size() << "\n";
    show(sol);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}