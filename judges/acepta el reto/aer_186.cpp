#include <iostream>
#include <vector>
using namespace std;

int main(){
    while(true){
        int num, globos;
        cin >> num >> globos;
        if(num == 0 && globos == 0) break;

        vector<int> equipos(num);

        int eq;
        string s;
        for(int i = 0; i < globos; i++){
            cin >> eq >> s;
            equipos[eq-1]++;
        }

        int max = 0, max_ind;
        bool empate = true;

        for(int i = 0; i < equipos.size(); i++){
            if(equipos[i] > max) {
                max = equipos[i];
                max_ind = i+1;
                empate = false;
            }
            else if(equipos[i] == max) empate = true;
        }
        if(num == 1) cout << "1" << endl;
        else if(empate) cout << "EMPATE" << endl;
        else cout << max_ind << endl;
    }
    return 0;
}
