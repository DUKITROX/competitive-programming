#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int j = 0; j<casos;j++){
        bool nueve = false, cero=false;
        double nota;
        for(int i = 0; i < 5; i++){
            cin >> nota;
            if(nota == 0.0) cero = true;
            else if(nota >= 9.0) nueve = true;
        }
        if(!nueve && cero) cout << "SUSPENSO DIRECTO" << endl;
        else cout << "MEDIA" << endl;
    }
    return 0;
}