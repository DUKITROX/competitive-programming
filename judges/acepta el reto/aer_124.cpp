#include <iostream>
using namespace std;

int main(){
    while(true){
        string s1, s2;
        int acarreo = 0, hay_acarreo = 0;
        cin >> s1 >> s2;
        if(s1 == "0" && s2 == "0") break;

        int len1 = s1.length();
        int len2 = s2.length();
        
        int sumando1;
        int sumando2;

        int len_max = len1;
        if(len1 < len2) len_max = len2;

        for(int i = 0; i < len_max + 1; i++){
            
            if(i < len1) sumando1 = s1[len1-i-1] - 48;
            else sumando1 = 0;

            if(i < len2) sumando2 = s2[len2-i-1] - 48;
            else sumando2 = 0;

            if((sumando1 + sumando2 + hay_acarreo) > 9){
                acarreo++;
                hay_acarreo = 1;
            }else hay_acarreo = 0;

        }

        cout << acarreo << endl;
    }
    return 0;
}