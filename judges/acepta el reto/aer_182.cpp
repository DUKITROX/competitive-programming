#include <iostream>
using namespace std;

int * to_array(int n){
    int len = to_string(n).length();
    int array[len];

    for(int j = 0; j < len; j++){
        array[j] = n % 10;
        n /= 10;
    }

    return array;
}

int main(){

    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int n;
        cin >> n;

        int len = to_string(n).length();
        int num = 1;
        int contador = 0;
        int * array = to_array(n);

        while(len != 1){
            for(int k = 0; k < len; k++){
                num *= array[k];   
            }
            len = to_string(num).length();
            array = 0;
            array = to_array(num);
            num = 1;
            contador++;
        }
        cout << contador << endl;
    }
    return 0;
}