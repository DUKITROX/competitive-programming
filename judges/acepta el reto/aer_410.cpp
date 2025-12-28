#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        string num;
        cin >> num;
        int len = num.length();

        bool digitos[10] = {false};
        int posicion = 0;

        for(int j = 0; j < len; j++){
            digitos[posicion] = true;
            posicion += num[posicion] - 48;
            posicion %= len;
        }      
        bool saltarin = true;
        for(int j = 0; j < len; j++){
            if(digitos[j] == false)
                saltarin = false;
        }

        if(saltarin && posicion == 0)
            cout << "SALTARINES" << endl;
        else
            cout << "NORMALES" << endl;
    }
    return 0;
}