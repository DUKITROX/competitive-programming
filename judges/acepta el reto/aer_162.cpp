#include <iostream>
using namespace std;

void pintar_linea(int n){
    cout << "|";
    for(int i = 0; i < n*8; i++){
        cout << "-";
    }
    cout << "|" << endl;
}

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }else{
            char c;
            cin >> c;

            bool blancos = true;
            pintar_linea(n);

            //lleva los dibujos de las lineas de manera vertical
            for(int i = 0; i < 8; i++){
                //pinta linea de la anchura dada
                for(int l = 0; l < n; l++){
                    cout << "|";
                    //dibujas horizontalmente
                    for(int j = 0; j < 8; j++){
                        if(blancos){
                            for(int k = 0; k < n; k++){
                                cout << " ";
                            }
                            blancos = false;
                        }else{
                            for(int k = 0; k < n; k++){
                                cout << c;
                            }
                            blancos = true;
                        }
                    }
                    cout << "|" << endl;
                }
                blancos = !blancos;
            }
            pintar_linea(n);
        }
    }
    return 0;
}