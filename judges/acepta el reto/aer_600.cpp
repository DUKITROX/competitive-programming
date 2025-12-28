#include <iostream>
using namespace std;

unsigned int matriz[300][300];
unsigned int minimos[300];
unsigned int maximos[300];

int main(){
    while(true){
        int filas, col;
        cin >> filas >> col;
        if(filas == 0 && col == 0) break;

        for(int i = 0; i < filas; i++){
            unsigned int min = 4294967295;
            unsigned int max = 0;
            int maxCont = 0, minCont = 0;
            for(int j = 0; j < col; j++){
                cin >> matriz[i][j];
                if(matriz[i][j] > max) {
                    max = matriz[i][j];
                    maxCont = 0;
                }
                else if (matriz[i][j] == max) maxCont = 0;

                if(matriz[i][j] < min){
                    min = matriz[i][j];
                    minCont = 0;
                }else if(matriz[i][j] == min) minCont++;
            }
            minimos[i] = minCont;
            maximos[i] = maxCont; 
        }
        bool existe = false;
        for(int i = 0; i < filas && !existe; i++){
            for(int j = 0; j < minimos[i] && !existe; j++){
                for(int k = 0; k < col && !existe; k++){
                    
                }
            }
        }
    }
    
    return 0;
}