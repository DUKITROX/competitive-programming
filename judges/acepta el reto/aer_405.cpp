#include <iostream>
#include <map>
using namespace std;

int main(){
    while(true){
        int n1, n2, primer_num;
        bool rango_de_paginas = false;

        cin >> n1;
        if(n1 == 0) break;
        primer_num = n1;
        map<int,int> m;

        while(true){
            cin >> n2;
            if(n2 == 0) break;

            if(n2 - n1 == 1){
                rango_de_paginas = true;
            }else{
                if(rango_de_paginas)cout << primer_num << "-" << n1 << ",";
                else cout << n1 << ",";
                primer_num = n2;
                rango_de_paginas = false;
            }
            n1 = n2;
        }
        if(rango_de_paginas)cout << primer_num << "-" << n1; 
        else cout << n1;
        cout << endl;
    }
    return 0;
}