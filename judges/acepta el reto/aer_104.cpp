#include <bits/stdc++.h>
using namespace std;

bool p = true, run = true;

int calc(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == 0 && b == 0 && c == 0 && d == 0) {
        run = false;
        return 0;
    }
    if(a == 0) a = calc();
    if(c == 0) c = calc();
    if(a*b != c*d)
        p = false;
    return a+c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(run){
        p = true;
        calc();
        if(run)
            cout << (p ? "SI\n" : "NO\n");
    }
    return 0;
}