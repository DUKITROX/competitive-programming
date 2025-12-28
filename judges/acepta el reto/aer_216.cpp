//---------------------------------------------------------
// Problema 216 Goteras
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

void casoDePrueba() {

	// TU C�DIGO AQU�
    int gotas, horas, minutos, segundos;
    cin >> gotas;

    horas = gotas / 3600;
    minutos = (gotas % 3600) / 60;
    segundos = gotas - horas*3600 - minutos*60;

    //setw ("setWidth") para establecer el numero de digitos por entero
    //setfill ("settFillCharacter") caracter con el que rellenar los espacios vacíos
    cout << setw(2) << setfill('0') << horas << ":" << setw(2) << setfill('0') << minutos << ":" << setw(2) << setfill('0') << segundos << endl;
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