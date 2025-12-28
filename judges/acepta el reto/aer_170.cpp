//---------------------------------------------------------
// Problema 170 Triángulos con piedras
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int n;
    cin >> n;
	if (n == 0)
		return false;
	else {
        int lado = 1, piedras_por_triangulo = 1, resto = 0;
        while(n > piedras_por_triangulo){
            lado++;
            piedras_por_triangulo += lado;
        }
        resto = n % piedras_por_triangulo;
        if(n % piedras_por_triangulo == 0){
            cout << lado << " " << resto << endl;
        }else{
            lado--;
            piedras_por_triangulo -= lado;
            resto = n % piedras_por_triangulo + 1;
            cout << lado << " " << resto << endl;
        }
		return true;
	}
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main