#include <iostream>
#include <string>
using namespace std;

int main(){
    while(true){
        string s;
        cin >> s;
        if(cin.fail()) break;

        int i = 0;
        char c = s[s.length()-1-i];

        while(c == '9' || c == '.'){
            i++;
            c = s[s.length()-1-i];
        }
        s[s.length()-1-i] += 1;
        for(int j = 0; j < i; j++){
            if(s[s.length()-1-j] != '.'){
                s[s.length()-1-j] = '0';
            }
        }
        if(i == s.length()){
            cout << "1";
            bool punto = true;
            for(int j = 0; j < 3; j++){
                if(s[j] == '.' || s.length() < 3) punto = false;
            }   
            if(punto) cout << '.';
        }
        cout << s << endl;
    }
    return 0;
}