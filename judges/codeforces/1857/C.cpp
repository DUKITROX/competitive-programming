#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){cout << arr[0]; for(int i = 0; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

void solve(){
    int n,m; cin >> n; m = (n*(n-1))/2; vi arr(m); cin >> arr; sort(arr.begin(),arr.end());
    int i = 0;
    while(i < m && n >= 0){
        n--;
        cout << arr[i] << " ";
        i += n;
    }
    cout << INF << "\n";

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}