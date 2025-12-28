#include <iostream>
#include <string>
using namespace std;

int main(){
    while(true){
        int letras = 0, exclamaciones = 0;
        string s;
        getline(cin, s);
        if(cin.fail()) break;

        int len = s.length();

        for(int i = 0; i < len; i++){
            if(s[i] == '!')
                exclamaciones++;
            else if((65 <= s[i] && s[i] <= 90) || (97 <= s[i] && s[i] <= 122))
                letras++;
        }
        if(exclamaciones > letras)
            cout << "ESGRITO" << endl;
        else
            cout << "escrito" << endl;
    }
    return 0;
}