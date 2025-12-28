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

bool calc(vi& arr, int& d, int& e, int n){
    for(int i = 0; i < e; i++){
        n -= arr[i]/d;
        arr[i]%d?n--:n;
        if(n<0)break;
    }
    return n>=0;
}

void solve(int n, int e){
    vi arr(e); int l = 1,r=-INF,m;
    for(int i = 0; i < e; i++){
        cin >> arr[i];
        r = max(arr[i],r);
    }
    int sol;
    while(l <= r){
        m = (r+l)/2;
        if(calc(arr, m, e, n)){
            r = m-1;
            sol = m;
        }else{
            l = m+1;
        }
    }
    cout << sol << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    while(cin >> n >> e) solve(n,e);
}