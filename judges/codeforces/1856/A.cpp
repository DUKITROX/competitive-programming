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
void show(vi arr){cout << arr[0]; for(int i = 0; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

void solve(){
    int n; cin >> n; 
    int ant,act;cin >> ant;int sol = 0;
    for(int i = 1; i < n; i++){
        cin >> act;
        if(ant>act)sol=max(sol,ant);
        ant = act;
    }
    cout << sol << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}