#include <iostream>
using namespace std;

int main(){
    while(true){
        int lado;
        cin >> lado;
        if(lado==0) break;

        string matriz[15];
        int res[15][15]={{0}};
        for(int i = 0; i < lado; i++) cin >> matriz[lado-i-1];

        int x,y,loops;
        res[0][0] = 1;
        for(int i = 1; i <= (lado-1)*2; i++){
            if(i+1 <= lado) {
                for(int j = 0; j < loops; j++){
                    x = j;
                    y = i-j;
                    if(matriz[y][x] == '.'){
                        if(y-1 >= 0) res[y][x] += res[y-1][x];
                        if(x-1 >= 0) res[y][x] += res[y][x-1];
                    }
                }
            }else{
                loops = (2*lado - 1) - i;
                for(int j = 0; j < loops; j++){
                    y = lado-1-j;
                    x = i-y;
                    if(matriz[y][x] == '.'){
                        if(y-1 >= 0) res[y][x] += res[y-1][x];
                        if(x-1 >= 0) res[y][x] += res[y][x-1];
                    }
                }
            } 
            
        }
        cout << res[lado-1][lado-1] << endl;
    }
    return 0;
}