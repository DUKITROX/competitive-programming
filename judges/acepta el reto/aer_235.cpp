#include <iostream>
using namespace std;

int main(){
    while(true){
        int filas, col;
        cin >> filas >> col;
        if(filas == 0 && col == 0) break;

        string pixelArt[150];
        for(int i = 0; i < filas*3; i++) cin >> pixelArt[i];
        int num;
        cin >> num;
        string cubo[3];
        
        for(int i = 0; i < num; i++){
            int x,y;
            for(int k=0; k < 3;k++) cin >> cubo[k];
            bool encontrado = true;
            for(int j = 0; j < filas; j++){
                for(int a = 0; a < col; a++){
                    encontrado=true;
                    if(pixelArt[j*3][a*3] != cubo[0][0]) encontrado=false;
                    if(pixelArt[j*3][a*3+1] != cubo[0][1]) encontrado=false;
                    if(pixelArt[j*3][a*3+2] != cubo[0][2]) encontrado=false;
                    if(pixelArt[j*3+1][a*3] != cubo[1][0]) encontrado=false;
                    if(pixelArt[j*3+1][a*3+1] != cubo[1][1]) encontrado=false;
                    if(pixelArt[j*3+1][a*3+2] != cubo[1][2]) encontrado=false;
                    if(pixelArt[j*3+2][a*3] != cubo[2][0]) encontrado=false;
                    if(pixelArt[j*3+2][a*3+1] != cubo[2][1]) encontrado=false;
                    if(pixelArt[j*3+2][a*3+2] != cubo[2][2]) encontrado=false;
                    if(encontrado){
                        x=j+1;
                        y=a+1;
                        break;
                    }
                }
                if(encontrado) break;
            }
            if(encontrado) cout << x << " " << y << endl;
            else cout << "NO SE USA" << endl;
        }
    }
    return 0;
}