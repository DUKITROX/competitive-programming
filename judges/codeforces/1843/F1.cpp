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
    int n; cin >> n;
    vector<ii> track, sol;
    track.push_back(make_pair(0,1));
    sol.push_back(make_pair(0,1));

    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == '+'){
            int u, val; cin >> u >> val; u--;
            int a = track[u].first, b = track[u].second;
            a += val; a = min(a,0);
            b += val; b = max(b,0);
            track.push_back(make_pair(a,b));

            a = min(a,sol[u].first);
            b = max(b, sol[u].second);
            sol.push_back(make_pair(a,b));
        }else{
            int u, k; cin >> u >> u >> k; u--;
            if(sol[u].first <= k && k <= sol[u].second) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}