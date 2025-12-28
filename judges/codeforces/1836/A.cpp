#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
#define first ff
#define second ss
const int INF = 1e9+7;

void solve(){
    int n; cin >> n; vi arr(n); map<int,int> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    bool pos = true;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0 && m[arr[i]] > m[arr[i]-1]) pos = false;
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}