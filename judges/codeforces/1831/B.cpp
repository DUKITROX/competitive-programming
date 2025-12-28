#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = 1e9;

void solve(){
    int n; cin >> n;
    int ant,act, cont = 1, sol = 1;
    int m1[400001] = {0}, m2[400001] = {0};

    cin >> ant; m1[ant] = 1;
    for(int i = 1; i < n; i++){
        cin >> act;
        if(act == ant) cont++;
        else cont = 1;
        m1[act] =max(m1[act],cont);
        ant = act;
    }

    cin >> ant; m2[ant] = 1; cont = 1;
    for(int i = 1; i < n; i++){
        cin >> act;
        if(act == ant) cont++;
        else cont = 1;
        m2[act] = max(m2[act], cont);
        ant = act;
    }

    for(int i = 1; i <= 2*n; i++) sol = max(sol, m1[i]+m2[i]);
    cout << sol << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}