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
    int n,m,k; cin >> n >> m >> k;
    int x,y; cin >> x >> y;
    bool pos = true;
    
    for(int i = 0; i < k; i++){
        int a,b; cin >> a >> b;
        if(!((abs(a-x) + abs(b-y))%2)) pos = false;
    }
    if(pos)cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}