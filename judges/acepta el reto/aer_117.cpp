//---------------------------------------------------------
// Problema 117 La fiesta aburrida
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

void casoDePrueba() {

	// TU C�DIGO AQU�
    string soy, nombre;
    cin >> soy >> nombre;

    cout << "Hola, " << nombre << "." << endl;

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