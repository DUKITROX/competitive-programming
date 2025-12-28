#include <iostream>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        else{
            for(int i = 0; i < n; i++){
                cout << "1";
            }
            cout << endl;
        }
    }
    return 0;
}