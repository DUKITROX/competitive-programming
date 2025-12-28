//---------------------------------------------------------
// Problema 607 Minimizando el castigo
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void casoDePrueba() {

	int n_lineas;
    double n_impresiones;
    cin >> n_lineas;

    n_impresiones = log2(n_lineas);

    if(int(n_impresiones) == n_impresiones){
        cout << int(n_impresiones) << endl;
    }else{
        cout << int(n_impresiones) + 1 << endl;
    }
} // casoDePrueba

//---------------------------------------------------------

int main() {

	unsigned int numCasos, i;

	cin >> numCasos;

	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;

} // main