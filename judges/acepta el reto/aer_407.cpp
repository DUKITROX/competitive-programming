#include <iostream>
using namespace std;

int main(){
    while(true){
        int c, p, t;
        cin >> c >> p >> t;
        if(c == 0 && p == 0 & t == 0) break;

        int p_final = p + t;
        if(p_final > c){
            int c_restantes = p_final - c;
            p_final = c - c_restantes;
        }
        cout << p_final << endl;
    }
    return 0;
}