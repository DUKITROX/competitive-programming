#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int c = 0; c < casos; c++){
        string nombre, s;
        int num;
        bool verd = false;
        int cont = 0;
        cin >> nombre >> num;
        for(int i = 0; i < num; i++){
            cin >> s;
            if(s == nombre && i == num-1 && i != 0) verd = true;
            if(nombre == s) cont++;
        }
        if(verd && cont == 1) cout << "VERDADERA" << endl;
        else cout << "FALSA" << endl;
    }
    return 0;
}