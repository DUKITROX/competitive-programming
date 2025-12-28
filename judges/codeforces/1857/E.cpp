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
    ll n; cin >> n; vector<ll> sum(n),sol(n);vector<pair<ll,ll> > arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; i++){
        if(i)sum[i] = sum[i-1]+arr[i].first;
        else sum[i] = arr[i].first;
    }
    if(n==1)cout << "1"<< "\n";
    else{
        for(int i = 0; i < n; i++){
            ll max = sum[n-1]-sum[i] - (arr[i].first)*(n-1-i) + n-1-i;
            ll min = (arr[i].first)*(i+1) - sum[i] + i+1;
            if(i==1){
                //cout<< "MAX " << sum[n-1]-sum[i] << " " << arr[i].first*(n-1-i) << " " << n-1-i << "\n";
                //cout << "MIN " << arr[i].first*(i+1) << " "<<sum[i] << " "<<i+1 << "\n";
            }
            //if(i == 1) cout << max << " " << min << "Ñ\n";
            max += min;
            sol[arr[i].second] = max;
        }
        for(int i = 0; i < n; i++) cout << sol[i] << " ";
        cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}