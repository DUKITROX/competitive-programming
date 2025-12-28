#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    while(true){
        int n;
        string s;
        cin >> n >> s;
        if(n == 9999 && s == "ZZZ") break;

        if(n+1 > 9999){
            n = 0;
            s[2]++;
            if(s[2]==65 || s[2]==69||s[2]==73||s[2]==79||s[2]==85){
                s[2]++;
            }

            if(s[2]>90){
                s[2] =  'B';
                s[1]++;
                if(s[1]==65 || s[1]==69||s[1]==73||s[1]==79||s[1]==85){
                    s[1]++;
                }

                if(s[1]>90){
                    s[1] = 'B';
                    s[0]++;
                    if(s[0]==65 || s[0]==69||s[0]==73||s[0]==79||s[0]==85){
                        s[0]++;
                    }
                    
                }
            }
        }else n++;
        cout <<setw(4) << setfill('0')<< n << " " << s << endl;
    }
    return 0;
}