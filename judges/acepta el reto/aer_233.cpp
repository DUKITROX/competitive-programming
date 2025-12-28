#include <iostream>
using namespace std;

int main(){
    while(true){
        int num;
        cin >> num;
        if(num == 0){
            return 0;
        }else{
            int resto = num % 9;
            int n = num / 9;
            if(resto > 0){
                cout << resto;
            }
            for(int i = 0; i < n; i++){
                cout << "9";
            }
            cout << "" << endl;
        }
    }
    return 0;
}