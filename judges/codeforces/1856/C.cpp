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
void show(vector<ll> arr){for(int i = 0; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

void solve(){
    ll n,k; cin >> n >> k; vector<ll> arr(n); cin >> arr; vector<ll> ARR(n), SOLID(n);
    ll M = 0, sol=0, K = k, indM;
    for(int i = 0; i < n; i++){
        ARR[i] = arr[i];
        SOLID[i] = arr[i];
        M = max(M,arr[i]);
    }
    sol = M;
    for(int i = 0; i < n; i++){
        if(SOLID[i] == M){
            for(int j = 0; j < n; j++) {
                arr[j] = SOLID[j];
                ARR[j] = SOLID[j];
            }

            k = K;
            indM = i;
            while(k > 0 && indM > 0){
                ll cant = min(k,arr[indM]-arr[indM-1]+1);
                arr[indM-1] += cant;
                sol = max(sol, arr[indM-1]);
                k -= cant;
                indM--;
            }
            k = K;
            for(int j = 0; j < n; j++)arr[j] = ARR[j];
            while(k > 0){
                ll top = ARR[i]+1, temp;
                bool pos = false;
                for(int j = i; j < n && !pos; j++){
                    if(ARR[j] >= top){
                        pos = true;
                    }else{
                        k -= top-ARR[j];
                        ARR[j] = top;
                    }
                    top--;
                }
                if(pos && k >= 0) sol = max(sol,ARR[i]);
                else break;

                temp = k;
                indM = i;
                for(int j = 0; j < n; j++)arr[j] = ARR[j];
                while(k > 0 && indM > 0){
                    ll cant = min(k,arr[indM]-arr[indM-1]+1);
                    arr[indM-1] += cant;
                    sol = max(sol, arr[indM-1]);
                    k -= cant;
                    indM--;
                }
                k = temp;
            }
        }
    }
    cout << sol << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}