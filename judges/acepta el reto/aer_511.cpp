#include <iostream>
#include <vector>
using namespace std;

int main(){
    while(true){
        int v1, v2;
        cin >> v1;
        if(cin.fail()) break;
        cin >> v2;

        vector<long long int> cantidad;
        vector<int> valor;

        long long int n1, n2;
        for(int i = 0; i < v1; i++){
            cin >> n1 >> n2;
            cantidad.push_back(n1);
            valor.push_back(n2);
        }

        long long int cant, val, k=0, minim;
        long long int suma = 0;

        for(int i = 0; i < v2; i++){
            cin >> cant >> val;
            while(cant > 0){
                minim = min(cant, cantidad[k]);
                suma += valor[k]*val*minim;

                cant -= minim;
                cantidad[k] -= minim;

                if(cantidad[k] == 0) k++;
            }
        }
        cout << suma << endl;
    }
    return 0;
}