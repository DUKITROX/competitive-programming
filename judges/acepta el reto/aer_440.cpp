#include <iostream>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        int grupos = 0, grupo_max = 1, grupo_min = 10000, alp_activos = 0;
        int alp_sig;

        int vel_min = -1;
//10 11 4 5 6 1
        for(int i = 0; i < n; i++){
            if(vel_min == -1){
                cin >> vel_min;
                alp_activos++;
            }else{
                cin >> alp_sig;
                if(alp_sig >= vel_min){
                    alp_activos++;
                }else{
                    grupos++;
                    if(alp_activos > grupo_max) grupo_max = alp_activos;
                    if(alp_activos < grupo_min) grupo_min = alp_activos;
                    alp_activos = 1;
                    vel_min = alp_sig;
                }
            }
        }
        grupos++;
        if(alp_activos > grupo_max) grupo_max = alp_activos;
        if(alp_activos < grupo_min) grupo_min = alp_activos;

        cout << grupos << " " << grupo_min << " " << grupo_max << endl;
    }
    return 0;
}