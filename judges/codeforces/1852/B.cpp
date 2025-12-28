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
void show(vi arr){cout << arr[0]; for(int i = 1; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

void solve(){
    int n; cin >> n; vii arr(n); for(int i = 0; i < n; i++){cin>>arr[i].first;arr[i].second=i;}; sort(arr.begin(), arr.end());
    int i=0,j=n-1,cont=0,act=n; bool pos = true;vi sol(n);
    while(i<=j && act > 0){
        if(arr[i].first > cont){
            sol[arr[j].second] = act;
            cont++;
            if(arr[j].first-cont != act-1) {
                pos = false;
            }
            j--;
        }else{
            sol[arr[i].second] = -act;
            i++;
        }
        act--;
    }
    if(pos){
        cout << "YES\n";
        show(sol);
    }else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}