#include <iostream>
#include <cmath>
using namespace std;

bool solapamiento(int x1, int y1, int r1, int x2, int y2, int r2){
    bool solapamiento;
    int distancia_centros = pow(abs(x1-x2), 2) + pow(abs(y1-y2), 2);
    int suma_radios = (r1+r2)*(r1+r2);
    if(distancia_centros < suma_radios) solapamiento = true;
    else solapamiento = false;
    return solapamiento;
}

int main(){
    int casos;
    cin >> casos;
    for(int c = 0; c < casos; c++){
        int playa[1000][1000] = {0};
        int num_sombrillas;
        cin >> num_sombrillas;

        int c1,c2,r;
        int solapamientos = 0;
        int circulos[100][3];

        for(int i = 0; i < num_sombrillas; i++){
            cin >> circulos[i][0] >> circulos[i][1] >> circulos[i][2];
            for(int j = 0; j < i; j++){
                if(solapamiento(circulos[i][0],circulos[i][1],circulos[i][2],circulos[j][0],circulos[j][1],circulos[j][2])) solapamientos++;
            }
        }
        cout << solapamientos << "\n";
    }
    return 0;
}