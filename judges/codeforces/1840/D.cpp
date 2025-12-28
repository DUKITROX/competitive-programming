#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;

vi arr;
int n;

bool ok(int t){
    int cur = arr[0] + t, workr = 1;
    for(int i = 0; i < n; i++){ 
        if(abs(arr[i] - cur) > t){
            workr++;
            cur = arr[i] + t;
        }
    }  
    return workr <= 3;
}

void solve(){
    cin >> n;
    arr = vi(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll l = 0, r = (arr[n-1]-arr[0]+1)/2, m, ans;
    while(l <= r){
        m = (l+r)/2;
        if(ok(m)){
            r = m-1;
            ans = m;
        }else{
            l = m+1;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}