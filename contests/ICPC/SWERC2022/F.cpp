#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

void solve(){
    int n,m; cin >> n >> m; vii arr(m);
    map<int,int> m;
    for(int i = 0; i < m; i++) {
        cin >> arr[i].first >> arr[i].second;
        m[arr[i].first]++; m[arr[i].second]++;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}