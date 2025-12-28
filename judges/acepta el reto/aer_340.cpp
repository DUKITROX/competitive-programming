//---------------------------------------------------------
// Problema 340 Cuadrados con cerillas
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

	// TU C�DIGO AQU�
    int cuadrados_horizontal, cuadrados_vertical, numero_cuadrados, numero_cerillas;
    cin >> cuadrados_horizontal >> cuadrados_vertical;

    numero_cuadrados = cuadrados_horizontal * cuadrados_vertical;
    numero_cerillas = numero_cuadrados * 2 + cuadrados_horizontal + cuadrados_vertical;

    cout << numero_cerillas << endl;
    
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