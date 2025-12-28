#include <iostream>
using namespace std;
int campo[50][50] = {{0}};
int main(){
    int casos;
    cin >> casos;
    while(casos--){
        int filas, col, pollos;
        cin >> filas >> col >> pollos;
        for(int i = 0; i < pollos; i++){
            int x,y,num;
            int cont = 2;
            char orientacion;
            bool ok = true;

            cin >> x >> y >> orientacion >> num;
            x--;
            y--;
            campo[x][y]++;
            if(orientacion == 'N' && x-1 >= 0){
                x--;
                y--;
                orientacion = 'E';
            }else if(orientacion == 'E' && y+1 < col){
                x--;
                y++;
                orientacion = 'S';
            }else if(orientacion == 'S' && x+1 < filas){
                x++;
                y++;
                orientacion = 'W';
            }else if(orientacion == 'W' && y-1 >= 0){
                x++;
                y--;
                orientacion = 'N';
            }else ok = false;
            while(num && ok){
                for(int k = 0; k < 3 && num && ok; k++){
                    for(int j = 0; j < cont && num && ok; j++){
                        if(orientacion == 'N' && x-1 >= 0){
                            x--;
                            campo[x][y]++;
                        }else if(orientacion == 'E' && y+1 < col){
                            y++;
                            campo[x][y]++;
                        }else if(orientacion == 'S' && x+1 < filas){
                            x++;
                            campo[x][y]++;
                        }else if(orientacion == 'W' && y-1 >= 0){
                            y--;
                            campo[x][y]++;
                        }else ok = false;
                        num--;
                    }
                    if(orientacion == 'N') orientacion = 'E';
                    else if(orientacion == 'E') orientacion = 'S';
                    else if(orientacion == 'S') orientacion = 'W';
                    else if(orientacion == 'W') orientacion = 'N';
                }
                cont++;
            }
        }
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < col-1; j++) cout << campo[i][j] << " ";
            cout << campo[i][col-1] << endl;
        }
        cout << "---" << endl;
    }
    return 0;
}