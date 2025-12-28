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

void solve(){
    int n,a; cin >> n; vi arr(n); for(int i = 0; i < n; i++) arr[i] = i+1;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(i) cout << " ";
        cout << arr[a];
        arr.erase(arr.begin()+a);
    }
    cout << "\n";
}
/*
4
3
2 1 0
3
1 0 0
4
2 1 1 0
4
1 2 1 0

3 2 1
2 1 3
3 2 4 1
2 4 3 1
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}