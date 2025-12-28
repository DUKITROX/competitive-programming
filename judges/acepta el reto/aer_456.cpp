//---------------------------------------------------------
// Problema 456 Tarta Sacher
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

	// TU C�DIGO AQU�
    int horizontal, vertical, necesarios, cuadraditos_tableta, numero_tabletas;
    cin >> horizontal >> vertical >> necesarios;

    cuadraditos_tableta = horizontal * vertical;
    numero_tabletas = (necesarios + cuadraditos_tableta - 1) / cuadraditos_tableta;

    cout << numero_tabletas << endl;
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