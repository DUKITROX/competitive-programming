#include <iostream>
using namespace std;

int main(){
    while(true){
        int n;
        bool es_identidad = true;

        cin >> n;
        if(n == 0) break;
        int matriz[n*n];

        for(int i = 0; i < n*n; i++){
            cin >> matriz[i];
        }

        bool es_uno = false;
        for(int i = 0; i < n*n; i++){
            for(int j = 0; j < n; j++){
                if(j*(n+1) == i){
                    es_uno = true;
                    break;
                }
            }

            if(es_uno && matriz[i] != 1) es_identidad = false;
            else if(!es_uno && matriz[i] != 0) es_identidad = false;

            es_uno = false;
        }

        if(es_identidad) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}