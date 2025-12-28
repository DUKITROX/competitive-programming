#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;

void solve(){
    int n,k; cin >> n >> k;
    vi last(k,0), cont(k,0);
    vii m(k);
    for(int i = 1; i <= n; i++){
        int a; cin >> a; a--;

        if(i-1-last[a] > m[a].first){
            m[a].second = m[a].first;
            m[a].first = i-1-last[a];
        }
        last[a] = i;
    }
    for(int i = 0; i < k; i++){
        if(n-last[i] > m[i].first){
            m[i].second = m[i].first;
            m[i].first = n-last[i];
        }
    }
    sort(m.begin(), m.end());
    cout << min(m[0].first/2, m[0].second) << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}