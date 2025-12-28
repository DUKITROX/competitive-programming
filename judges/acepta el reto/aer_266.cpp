#include <iostream>
#include <map>
using namespace std;

string cuadro[500];
int main(){
    while(true){
        int filas, col;
        cin >> filas >> col;
        if(filas == 0 && col == 0) break;

        map<int,int> mapa;
        for(int i = 0;i < filas; i++) {
            cin >> cuadro[i];
            for(int j = 0; j < col; j++) mapa[cuadro[i][j]] = cuadro[i][j];
        }

        int num;
        cin >> num;
        char ini, fin;
        for(int p=0; p<num;p++){
            cin >>ini >> fin;
            for(auto m : mapa){
                if(m.second == ini) mapa[m.first] = fin;
            }
        }
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < col; j++){
                cout << mapa[cuadro[i][j]];
            }
            cout << endl;
        }
    }
    return 0;
}