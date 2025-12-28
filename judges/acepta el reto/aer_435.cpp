#include <iostream>
using namespace std;

int main(){
    while(true){
        string num;
        cin >> num;
        if(cin.fail()) break;

        int len = num.length();
        int n0=0, n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0;
        for(int i = 0; i < len; i++){
            char c = num[i];
            switch (c){
                case '0':
                    n0++;
                    break;
                case '1':
                    n1++;
                    break;
                case '2':
                    n2++;
                    break;
                case '3':
                    n3++;
                    break;
                case '4':
                    n4++;
                    break;
                case '5':
                    n5++;
                    break;
                case '6':
                    n6++;
                    break;
                case '7':
                    n7++;
                    break;
                case '8':
                    n8++;
                    break;
                case '9':
                    n9++;
                    break;
            }
        }
        if(n1==n0&&n1==n2&&n1==n3&&n1==n4&&n1==n5&&n1==n6&&n1==n7&&n1==n8&&n1==n9) cout << "subnormal" << endl;
        else cout << "no subnormal" << endl;
    }
}