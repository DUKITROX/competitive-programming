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
    int n; cin >> n; vi arr(n); cin >> arr; bool p = true; int l = 1, j = 1;
    while(j + l <= n && p){
        for(int i = 0; i < l-1; i++) 
            if(arr[j+i] > arr[j+i+1]) p = false;
        j += l;
        l <<= 1;
    }
    for(int i = j; i < n-1; i++)
        if(arr[i] > arr[i+1]) p = false;
    
    if(p) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}