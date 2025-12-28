#include <iostream>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        int a,b;
        cin >> a;
        n--;
        bool x=true;
        while(n--){
            cin >> b;
            if(b<=a)
                x = false;
            a = b;
        }
        if(x) cout << "SI\n";
        else cout << "NO\n";
    }
    return 0;
}