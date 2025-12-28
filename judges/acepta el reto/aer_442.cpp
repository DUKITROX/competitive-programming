#include <iostream>
using namespace std;

int main(){
    while(true){
        string s1, s2;
        cin >> s1;
        if(cin.fail()) break;
        cin >> s2;

        if(s2 == "CamelCase"){
            bool poner_mayus = true;
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] == '-' || s1[i] == '_'){
                     poner_mayus = true;
                     s1.erase(i, 1);
                }
                if(poner_mayus){
                    if(!isupper(s1[i])) s1[i] -= 32;
                    poner_mayus = false;
                }
            }
        }else if(s2 == "snake_case"){
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] == '-') s1[i] = '_';
                else if(isupper(s1[i])){
                    s1[i] += 32;
                    s1.insert(i, "_");
                };
            }
            if(s1[0] == '_') s1.erase(0, 1);
        }else{
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] == '_') s1[i] = '-';
                else if(isupper(s1[i])){
                    s1[i] += 32;
                    s1.insert(i, "-");
                };
            }
            if(s1[0] == '-') s1.erase(0, 1);
        }
        
        cout << s1 << endl;
    }
    return 0;
}