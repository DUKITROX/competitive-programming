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
    long long n,k,g; cin >> n >> k >> g;
    long long  tot = k*g, G = ceil((long double)g/(long double)2);
    long long a = (n-1)*(G-1), b = tot-a;
    if(n*(G-1) >= tot) cout << tot << "\n";
    else if(b%g >= G) {
        if(a - (g - b%g) <= 0) cout << "0\n";
        else cout << a - (g - b%g) << "\n";
    }
    else cout << a + b%g << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}