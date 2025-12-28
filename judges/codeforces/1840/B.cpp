#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;

void solve(){
    unsigned long long n,k; cin >> n >> k;
    if(k > 36) cout << n+1 << "\n";
    else if(n >= ((1ULL<<k)-1)) cout << (1ULL<<k) << "\n";
    else cout << n+1 << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}