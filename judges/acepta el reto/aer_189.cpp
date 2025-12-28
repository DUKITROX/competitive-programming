#include <iostream>
#include <map>
using namespace std;

int main(){
    while(true){
        int num_pasajeros;
        cin >> num_pasajeros;
        if(num_pasajeros == 0) break;

        int pasajeros[1000000];
        map <int, int> cubiertas;
        for(int i = 0; i < num_pasajeros; i++){
            cin >> pasajeros[i];
            cubiertas[pasajeros[i]]++;
        }

        int num_acciones, accion;
        cin >> num_acciones;
        string sAccion;

        for(int i = 0; i < num_acciones; i++){
            cin >> sAccion >> accion;
            if(sAccion == "EMBARQUE"){
                cout << num_pasajeros-cubiertas[accion] << endl;
                int k = 0;
                for(int j = 0; j < num_pasajeros; j++){
                    if(pasajeros[j] != accion){
                        pasajeros[k] = pasajeros[j];
                        k++; 
                    }
                }
                num_pasajeros -= cubiertas[accion];
            }else{
                cout << pasajeros[accion-1] << endl;
            }
        }
        cout << "*" << endl;
    }
    return 0;
}