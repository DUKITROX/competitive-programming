#include <iostream>
using namespace std;

int main(){
    while(true){
        int n;
        bool falta_pieza = true;
        cin >> n;
        if(n == 0) break;
        int piezas[n-1];
        for(int i = 0; i < n-1; i++) cin >> piezas[i];

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < n-1; j++){
                if(piezas[j] == i){
                    falta_pieza = false;
                    break;
                }
                else falta_pieza = true;
            }
            if(falta_pieza){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}