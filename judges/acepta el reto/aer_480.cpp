#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int uvas, podridas, sanas, malas;
        cin >> uvas >> podridas >> sanas;

        malas = (uvas / sanas) * podridas;
        if(uvas%sanas != 0){
            if(uvas%sanas >= podridas)
                malas += podridas;
            else malas += uvas%sanas;
        } 
        cout << malas << endl;
    }
    return 0;
}