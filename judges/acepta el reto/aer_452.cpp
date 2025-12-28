#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        int num;
        cin >> num;
        if (num == 0) break;

        vector <int> resultados;
        bool visitados[2000] = {false};
        int valores[num];

        for(int i = 0; i < num; i++) cin >> valores [i];

        for(int i = 0; i < num; i++){
            for(int j = i+1; j < num; j++){
                if(!visitados[abs(valores[i]-valores[j])]){
                    visitados[abs(valores[i]-valores[j])] = true;
                    resultados.push_back(abs(valores[i]-valores[j]));
                }
            }
        }
        sort(resultados.begin(), resultados.end());
        cout << resultados[0];
        for(int i = 1; i < resultados.size(); i++) cout << " " << resultados[i];
        cout << endl;
    }
    return 0;
}
