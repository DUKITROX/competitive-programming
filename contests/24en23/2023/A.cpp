#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int x1,x2,y1,y2;
        cin >> x1>>y1>>x2>>y2;
        if(!x1&&!x2&&!y1&&!y2) break;

        if(x1 == x2 || y1 == y2 || x1+y1 == x2+y2 || abs(x2-x1) == abs(y2-y1)) cout << "SI\n";
        else cout << "NO\n";
    }
}