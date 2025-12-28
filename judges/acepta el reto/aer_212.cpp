#include <iostream>
using namespace std;

int main(){
    while(true){
        int num_calles, num_intersecciones;
        cin >> num_calles;
        if(num_calles == 0) break;
        cin >> num_intersecciones;

        int calles[num_calles*2];

        for(int i = 0; i < num_calles*2; i++){
            cin >> calles[i];
        }

        int contador = 0;
        int intersecciones_validas = 0;

        for(int i = 1; i <= num_intersecciones; i++){
            contador = 0;
            for(int j = 0; j < num_calles*2; j++){
                if(calles[j] == i) contador++;
            }
            if(contador%2) intersecciones_validas++;
        }

        if(intersecciones_validas < 3) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}