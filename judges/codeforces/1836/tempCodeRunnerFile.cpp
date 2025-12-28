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
    int n,k,g; cin >> n >> k >> g;
    int a = (n-1)*(g/2-1), tot = k*g, b = tot-a;

    if(n*(g/2-1) >= tot) cout << tot << "\n";
    else if(b%g >= g/2) {
        if(a - (g - b&g) < 0) cout << "0\n";
        else cout << a - (g - b&g) << "\n";
    }
    else cout << a + b%g << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}