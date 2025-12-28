#include <bits/stdc++.h>
using namespace std;
double p[6];
string dias[6] = {"MARTES","MIERCOLES","JUEVES","VIERNES","SABADO","DOMINGO"};
int main(){
    while(true){
        double price;
        cin >> price;
        if(price == -1) break;
        p[0] = price;
        bool m=false,M=0;
        double mi = INT_MAX,MA = 0;
        string mii,MII;
        if(price < mi){
            m = false;
            mi = price;
            mii = "MARTES";
        }else if(price == mi){
            m = true;
            mii = "EMPATE";
        }
        if(price > MA){
            M = false;
            MA = price;
            MII = "MARTES";
        }else if(price == MA){
            MA = true;
            MII = "EMPATE";
        }
        double sum = price;
        for(int i = 1; i < 6; i++){
            cin >> p[i];
            if(i != 5) sum += p[i];
            price = p[i];
            if(price < mi){
                m = false;
                mi = price;
                mii = dias[i];
            }else if(price == mi){
                m = true;
                mii = "EMPATE";
            }
            if(price > MA){
                M = false;
                MA = price;
                MII = dias[i];
            }else if(price == MA){
                MII = "EMPATE";
                MA = true;
            }
        }
        cout << MII << " " << mii << " ";
        if(p[5] > (double)sum/5) cout << "SI";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}