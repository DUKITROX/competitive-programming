#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = 1e9;

void solve(){
    int n; cin >> n;
    int N = n+1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cout << N-a << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}