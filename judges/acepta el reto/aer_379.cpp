#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        int vector[n];
        for(int i = 0; i < n; i++){
            cin >> vector[i];
        }

        bool ningun_numero_igual = true;
        for(int i = 0; i < n-1; i++){
            if(vector[i] == vector[i+1])ningun_numero_igual = false;
        }

        if(ningun_numero_igual){
            cout << vector[0]+1;
            for(int i = 1; i < n; i++) cout << " " << vector[0]+1;
            cout << endl;
        }else{
            if(vector[n-2] == vector[n-1]){
                vector[n-1]++;
            }else{
                int i = 0, num_limite;
                while(vector[n-i-1] != vector[n-i-2]){
                    i++;
                }
                num_limite = vector[n-i];
                for(int j = 0; j < i+1; j++){
                    vector[n-j-1] = num_limite;
                }
            }
            cout << vector[0];
            for(int i = 1; i < n; i++) cout << " " << vector[i] ;
            cout << endl;
        }
    }
    return 0;
}