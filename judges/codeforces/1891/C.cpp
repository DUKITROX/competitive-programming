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
    ll n; cin >> n; vector<ll> arr(n); cin >> arr;
    ll cont = 0; ll i = 0, j = n-1; ll sum = 0;
    sort(arr.begin(), arr.end());
    while(true){
        for(; i < j; i++){
            sum += arr[i];
            if(sum > arr[j]){
                arr[i] = sum-arr[j];
                sum = arr[j];
                break;
            }
        }
        if(i < j){
            cont += sum + 1;
            sum = 0;
            arr[j] = 0;
        }else break;
        j--;
    }
    if(sum){
        cont += sum + 1 + (arr[j]-sum)/2 + (arr[j]-sum)%2;
    }else if(arr[j]){
        cont += (arr[j]-sum)/2 + (arr[j]-sum)%2;
    }
    cout << cont << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}