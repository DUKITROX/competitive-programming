#include <iostream>
using namespace std;

int main(){
    while(true){
        int num;
        cin >> num;
        if(num==0)break;

        int planetas[5];
        for(int i = 0; i < num; i++) cin >> planetas[i];
        int D,d,r;
        int mcm = planetas[0];
        for(int i = 1; i < num; i++){
            D = mcm;
            d = planetas[i];
            while(D%d!=0){
                r = D%d;
                D = d;
                d = r;
            }
            mcm = (mcm*planetas[i]) / d;
        }
        cout << mcm << endl;
    }
    return 0;
}