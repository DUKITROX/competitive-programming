#include <iostream>
using namespace std;

int main(){
    while(true){
        int num1, num2;
        cin >> num1 >> num2;
        if(num1 == 0 && num2 == 0) break;

        char c = 'i' - num1;
        
        cout << c << num2 << endl;
    }
    return 0;
}