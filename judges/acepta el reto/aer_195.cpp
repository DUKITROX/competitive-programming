#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    while(true){
        vector<double> notas;
        double aux;
        cin >> aux;
        if(cin.fail()) break;

        notas.push_back(aux);
        for(int i = 0; i < 6; i++){
            cin >> aux;
            notas.push_back(aux);
        }
        sort(notas.begin(), notas.end());

        double suma = 0;
        for(int i = 2; i < 5; i++) suma += notas[i];

        suma*=2;
        cout << int(suma) << endl;
    }
    return 0;
}