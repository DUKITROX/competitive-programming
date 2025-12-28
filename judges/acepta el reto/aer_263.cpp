#include <iostream>
using namespace std;

string cubo[50];

int main(){
    while(true){
        int lado;
        cin >> lado;
        if(lado == 0) break;

        for(int i = 0; i < lado; i++) cin >> cubo[i];

        char a='a';
        int b;
        while(true){
            cin >> a;
            if(a=='x') break;
            cin >> b;
            if(a == 'f'){
                if(b>0){
                    b--;
                    a = cubo[b][lado-1];
                    for(int i = lado-1; i >= 1; i--){
                        cubo[b][i] = cubo[b][i-1];
                    }
                    cubo[b][0] = a;
                }else{
                    b++;
                    a = cubo[-b][0];
                    for(int i = 0; i < lado-1; i++){
                        cubo[-b][i] = cubo[-b][i+1];
                    }
                    cubo[-b][lado-1] = a;
                }
            }else{
                if(b>0){
                    b--;
                    a = cubo[lado-1][b];
                    for(int i = lado-1; i >= 1; i--){
                        cubo[i][b] = cubo[i-1][b];
                    }
                    cubo[0][b] = a;
                }else{
                    b++;
                    a = cubo[0][-b];
                    for(int i = 0; i < lado-1; i++){
                        cubo[i][-b] = cubo[i+1][-b];
                    }
                    cubo[lado-1][-b] = a;
                }
            }
        }
        for(int i = 0; i < lado; i++) cout << cubo[i] << endl;
        cout << "---" << endl;
    }
    return 0;
}