#include <iostream>
using namespace std;

int main(){
    while(true){
        int coste, dias;
        cin >> coste;
        if(cin.fail()) break;
        cin >> dias;

        int habitaciones[dias];
        unsigned long long suma = 0;
        unsigned long long num1, num2, var_coste = 1;
        bool suma_medio = false;

        for(int i = 0; i < dias; i++) cin >> habitaciones[i];

        for(int i = 0; i < dias/2; i++){
            num1 = habitaciones[i];
            num2 = habitaciones[dias-i-1];

            num1 = ((num1*coste) % 78787 * var_coste) % 78787;
            num2 = ((num2*coste) % 78787 * var_coste) % 78787;
            suma = num1+num2+suma;
            suma %= 78787;

            var_coste = (var_coste*3) % 78787;
        }
        if(dias%2){
            suma += ((habitaciones[dias/2]*coste)%78787 * var_coste) % 78787;
            suma %= 78787;
        }
        cout << suma % 78787 << endl;
    }
    return 0;
}

// n1 * n2 = n3
// (n1 * n2) % 78787 == n3'
//  (n1 % 78787 * n2 % 78787) = n3'