#include <iostream>
using namespace std;

int main(){

    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int dientes_sup[6];
        int dientes_inf[6];
        int n, suma;
        bool encajan = true;

        for(int j = 0; j < 6; j++){
            cin >> n;
            dientes_sup[j] = n;
        }
        for(int j = 0; j < 6; j++){
            cin >> n;
            dientes_inf[j] = n;
        }
        suma = dientes_sup[0] + dientes_inf[0];

        for(int j = 0; j < 6; j++){
            if(dientes_sup[j] + dientes_inf[j] != suma) encajan = false;
        }

        if(encajan) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}