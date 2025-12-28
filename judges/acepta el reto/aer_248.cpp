#include <iostream>
#include <vector>
using namespace std;

int main(){
    while(true){
        int num, aux;
        cin >> num;
        if(num == 0) break;

        cin >> aux;
        int global_max=aux, local_max=aux;
        for(int i = 1; i < num; i++){
            local_max = max(local_max, aux+local_max);
            global_max = max(local_max, global_max);

            cin >> aux;
        }
        cout << global_max << endl;
    }
    return 0;
}