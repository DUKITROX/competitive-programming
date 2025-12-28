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

ofstream file;

void solve(){
    int n; cin >> n; vector<string> arr(n); cin >> arr;
    int q; cin >> q; string s;
    for(int i = 0; i < q; i++){
        int a,b;char c; cin >> a >> c >> b;
        file << arr[b][a] << endl;
    }
}
int main(){
    file.open("A5.out");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    file.close();
}