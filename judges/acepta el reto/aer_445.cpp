#include <iostream>
using namespace std;

pair<int,int> clases[200000];

int main(){
    while(true){
        int num;
        cin >> num;
        if(cin.fail()) break;
        int cont, cont_max=0;
        for(int i = 0; i < num; i++){
            cont=0;
            cin >> clases[i].first;
            cin >> clases[i].second;
            for(int j = 0; j < i; j++){
                if((clases[j].second>clases[i].first && clases[j].first<clases[i].second)){
                    cont++;
                }
            }
            if(cont != cont_max) cont_max = cont;
        }
        cout << cont_max << endl;
    }
    return 0;
}