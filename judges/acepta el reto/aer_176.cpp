#include <iostream>
using namespace std;
string matriz[1000];
int main(){
    while(true){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int a, l;
        cin >> a >> l;
        if(a == 0 || l == 0) break;

        string aux;
        for(int i = 0; i < l; i++){
            cin >> matriz[i];
        }
        int cont=0, c=0;
        for(int i = 1; i < l-1; i++){
            for(int j = 1; j < a-1; j++){
                if(matriz[i][j]=='-'){
                    c=0;
                    if(matriz[i-1][j-1] == '*') c++;
                    if(matriz[i-1][j] == '*') c++;
                    if(matriz[i-1][j+1] == '*') c++;
                    if(matriz[i][j-1] == '*') c++;
                    if(matriz[i][j+1] == '*') c++;
                    if(matriz[i+1][j-1] == '*') c++;
                    if(matriz[i+1][j] == '*') c++;
                    if(matriz[i+1][j+1] == '*') c++;
                    if(c>=6)cont++;
                }
            }
        }
        cout << cont << endl;
    }
    return 0;
}