#include <iostream>
#include <vector>
using namespace std;

int main(){
    while(true){
        int num;
        cin >> num;
        if(cin.fail()) break;

        vector<int> montones;
        bool colocado = false;
        int total = 0, aux;

        for(int i = 0; i < num; i++){
            cin >> aux;
            colocado = false;
            for(int j = 0; j < montones.size(); j++){
                if(montones[j] > aux){
                    montones[j] = aux;
                    colocado = true;
                    break;
                }
            }
            if(!colocado){
                montones.push_back(aux);
                total++;
            }
        }
        cout << total << endl;
    }
    return 0;
}