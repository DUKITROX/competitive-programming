#include <iostream>
using namespace std;

int main(){
    while(true){
        int n1, n2;
        cin >> n1 >> n2;
        if(n1 == 0 && n2 == 0){
            break;
        }else{
            if(n1 <= n2){
                cout << "10" << endl;
            }else{
                if(n1%n2 == 0)cout << n1/n2 * 10<< endl;
                else cout << n1/n2 *10 + 10 << endl;
            }
        }
    }
    return 0;
}