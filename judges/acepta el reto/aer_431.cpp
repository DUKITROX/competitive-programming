#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        int num_familias;
        cin >> num_familias;
        if(num_familias == 0) break;

        vector<int>midi;
        for(int i = 0; i < num_familias; i++){
            int num_hijos, milstr, aux, max=0;
            cin >> num_hijos >> milstr;
            for(int j = 0; j < num_hijos; j++){
                cin >> aux;
                aux *= milstr;
                if(aux > max) max = aux;
            }
            midi.push_back(aux);
        }
        sort(midi.begin(), midi.end(), greater<int>());
        for(int i = 0; i < midi.size(); i++) cout << midi[i] << " ";
        cout << endl;
    }
    return 0;
}