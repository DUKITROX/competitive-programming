#include <iostream>
#include <math.h>
using namespace std;

int main(){
    while(true){
        double n;
        cin >> n;
        if(cin.fail()) break;

        if(floor(n) != n){
            cout << n << endl;
        }else{
            cout << int(n) << endl;
        }
    }
    return 0;
}