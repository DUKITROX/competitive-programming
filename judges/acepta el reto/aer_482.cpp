#include <iostream>
using namespace std;

int main(){
    char c;

    while(true){
        int negro = 0, gris = 0;
        cin >> c;
        if(c == '.') break;
        else{
            while(true){
                if(c == 'N') negro++;
                else if(c == 'G') gris++;
                else if (c == '.') break;
                cin >> c;
            }
            if(negro%2 == 0 && gris%2 == 0) cout << "EMPAREJADOS" << endl;
            else if(negro%2 == 0 && gris%2 == 1) cout << "GRIS SOLITARIO" << endl;
            else if(negro%2 == 1 && gris%2 == 0) cout << "NEGRO SOLITARIO" << endl;
            else cout << "PAREJA MIXTA" << endl;
        }
    }
    return 0;
}