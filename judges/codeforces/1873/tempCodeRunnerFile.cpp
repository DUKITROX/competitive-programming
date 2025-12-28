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
    ll n,M; cin >> n >> M; vector<ll> arr(n), cant(n); cin >> cant >> arr;
    ll cont = cant[0], prev = arr[0], len = 1, last = 0, sol = 0;
    for(int i = 1; i < n; i++){
        if(cant[i] <= M) sol = max(sol,1LL);
        if(!(prev%arr[i])){
            //cout << "A\n";
            while(cont + cant[i] > M && last < i) {
                cont -= cant[last];
                last++;
                len--;
            }
            if(cont + cant[i] <= M){
                cont += cant[i];
                len++;
                sol = max(sol,len);
            }else{
                prev = arr[i]; 
                cont = cant[i];
                len = 1;
                last = i;
            }
        }else{
            cont = cant[i];
            len = 1;
            last = i;
        }
        prev = arr[i]; 
    }
    cout << sol << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}