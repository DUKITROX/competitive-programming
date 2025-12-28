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
    int n,m,a=0,b=0,aux; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> aux;
        a ^= aux;
    }
    for(int i = 0; i < m; i++){
        cin >> aux;
        b |= aux;
    }

    if(n%2){
        b |= a;
        cout << a << " " << b << "\n";
    }else{
        int max = a;
        b = ~b;
        a &= b;
        cout << a << " " << max << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}