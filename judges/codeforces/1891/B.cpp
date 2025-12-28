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

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return (a.second < b.second);
}
bool cmp1(pair<ll,ll> a, pair<ll,ll> b){
    return (LSOne(a.first) > LSOne(b.first));
}

void solve(){
    ll n,q; cin >> n >> q; vector<pair<ll,ll> > arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first; arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), cmp1);
    for(int i = 0; i < q; i++){
        ll o; cin >> o;
        ll l = 0, r = n-1, m, M = -1;
        while(l <= r){
            m = (r+l)/2;
            //cout << "m: " << m << endl;
            if((arr[m].first % (1<<o)) == 0) {
                l = m+1;
                M = max(M,m);
                //cout << "M: " << M << endl;
            }
            else r = m-1;
        }
        o--;
        for(int j = 0; j <= M; j++)
            arr[j].first += (1<<o);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(int i = 0; i < n; i++) cout << arr[i].first << " ";
    cout << "\n";
}
/*
4
5 1
4 4 3 2 1
2 
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}