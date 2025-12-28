#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    // signed === int
    int tt; cin >> tt; while(tt--){
        int a,b; cin >> a >> b;
        a--; b--;
        cout << (a/1000 == b/1000 ? "NO" : "SI") << "\n";
    }
}
/*
3
1974 2025
1910 2000
2000 2089

*/