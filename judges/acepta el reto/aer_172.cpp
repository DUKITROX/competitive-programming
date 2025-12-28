#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != 0){
        if(n == 0) break;

        string mesa;
        cin >> mesa;
        bool derecha = false, izquierda = false;
        int i = 0;

        while((!izquierda || !derecha) && i < mesa.length()){
            if(mesa[i] == 'I') izquierda = true;
            else if(mesa[i] == 'D') derecha = true;
            i++;
        }
        if(derecha&&izquierda) cout << "ALGUNO NO COME" << endl;
        else cout << "TODOS COMEN" << endl;

        cin >> n;
    }
    return 0;
}





// 6   "."  .D.I.



/*#include <iostream>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        bool derecha = false, izquierda = false;
        string mesa;
        cin >> mesa;

        for(int i = 0; i < mesa.length(); i++){
            if(mesa[i] == 'I') izquierda = true;
            else if(mesa[i] == 'D') derecha = true;
            if(derecha && izquierda) break;
        }

        derecha&&izquierda?cout<<"ALGUNO NO COME"<<endl:cout<<"TODOS COMEN"<<endl;
    }
    return 0;
}*/