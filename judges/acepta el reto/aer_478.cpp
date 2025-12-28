#include <iostream>
using namespace std;

int main(){
    while(true){
        int num_hechizos;
        unsigned long long int dano, dano_restante, total=0;
        cin >> num_hechizos;
        if(num_hechizos == 0) break;
        int hechizos[num_hechizos];

        for(int i = 0; i < num_hechizos; i++){
            cin >> hechizos[i];
            total += hechizos[i];
        }
        cin >> dano;
        dano_restante = total-dano;

        int i = 0;
        int j = num_hechizos-1;
        while(true){
            if(hechizos[i] + hechizos[j] == dano_restante){
                cout << hechizos[i] << " " << hechizos[j] << endl;
                break;
            }else if(hechizos[i]+hechizos[j] > dano_restante) j--;
            else i++;
        }
    }
    return 0;
}