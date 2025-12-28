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
    int n;
    cin >> n;
    if(n <= 4)cout << "Bob\n";
    else cout << "Alice\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}