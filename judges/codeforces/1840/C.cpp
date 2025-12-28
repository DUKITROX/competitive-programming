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
    long long n,k,q; cin >> n >> k >> q;
    long long sol = 0, a, cont = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a<=q)cont++;
        else {
            if(cont >= k){
                int b = cont - k + 1;
                sol += (b*(b+1))/2;
            }
            cont = 0;
        }
    }
    if(cont >= k){
        long long b = cont - k + 1;
        sol += (b*(b+1))/2;
    }
    cout << sol << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}