
#include <iostream>
using namespace std;

int main(){
    while(true){
        int n, p;
        cin >> n >> p;
        if(n == 0 || p == 0) break;

        unsigned long long suma = 0;
        unsigned long long num;

        for(int i = 1; i <= n; i++){
            num = i;
            for(int j = 1; j < p; j++){
                num *= i;
                num %= 46337;
            }
            suma = suma + num % 46337;
            suma %= 46337;
        }
        cout << suma << endl;
    }
    return 0;
}