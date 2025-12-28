//---------------------------------------------------------
// Problema 191 Los problemas de ser rico
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

	// TU C�DIGO AQU�
    int numero_compartimentos, capacidad_maxima, capacidad_diferencia, capacidad_total;
    cin >> numero_compartimentos >> capacidad_maxima >> capacidad_diferencia;

    capacidad_total = capacidad_maxima;
    for (;numero_compartimentos > 1; numero_compartimentos--){
        capacidad_maxima = capacidad_maxima - capacidad_diferencia;
        capacidad_total = capacidad_total + capacidad_maxima;
    }

    cout << capacidad_total << endl;
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