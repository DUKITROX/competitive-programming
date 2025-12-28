#include <iostream>
using namespace std;

int main(){
    while(true){
        int n1, n2_fin;
        cin >> n1 >> n2_fin;
        if (n1 == 0 && n2_fin == 0) break;

        int c = 0, c_max = 0, n, n_sig;
        int n2 = n2_fin;
        bool comiendo = false;
        for(int i = 0; i < n1; i++){
            cin >> n;
            if(!comiendo && n == 1){
                comiendo = true;
                c++;
                if(c > c_max) c_max = c;
            }else if(comiendo){
                if(n == 0){
                    if(n2 > 0){
                        n2--;
                        c++;
                    }else{
                        //terminamos de comer
                        comiendo = false;
                        n2 = n2_fin;
                        c = 0;
                    }
                }else{
                    c++;
                    n2 = n2_fin;
                    if(c > c_max) c_max = c;
                }
            }
        }
        cout << c_max << endl;
    }
    return 0;
}