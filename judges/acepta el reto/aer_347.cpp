#include <iostream>
using namespace std;

int cont = 0;
void calc(int a, int b){
    int m = min(a,b), M = max(a,b);
    if(m < 10) return;
    cont++;
    calc(M-m,m);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cont = 0;
        int a,b,m,M;
        cin >> a >> b;
        if(a == 0 && b==0) break;
        m = min(a,b);
        M = max(a,b);
        while(m >= 10){
            m = min(a,b);
            M = max(a,b);
        }
        cout << cont <<"\n";
    }
    return 0;
}