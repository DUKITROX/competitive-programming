#include <iostream>
using namespace std;

int main(){
    while(true){
        int n, num_triangulos = 0, contador = 0;
        cin >> n;
        if (n == 0) break;

        for(int i = 1; i <= n; i++){
            num_triangulos += i;
        }
        cout << num_triangulos*3 << endl;
    }
    return 0;
}