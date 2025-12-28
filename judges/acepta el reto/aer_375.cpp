#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    while(true){
        string pista;
        char letra;
        cin >> pista;
        if(cin.fail())break;
        
        int num = stoi(pista.substr(0,2));
        if(pista.length()>2){
            letra = pista[2];
            if(letra == 'R') letra = 'L';
            else if(letra == 'L') letra = 'R';
            num += 18;
            if(num > 36) num -= 36;
            cout << setw(2) << setfill('0') << num << letra << endl;
        }else{
            num += 18;
            if(num > 36) num -= 36;
            cout << setw(2) << setfill('0') << num << endl;}
    }
    return 0;
}