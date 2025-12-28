//---------------------------------------------------------
// Problema 360 Rellenando el agua de la fuente
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

	int agua_inicial, agua_minima, perdida_agua, agua_remanente, contador = 0;
    cin >> agua_inicial >> agua_minima >> perdida_agua;
    agua_remanente = agua_inicial;

    while(perdida_agua != -1){
        agua_remanente -= perdida_agua;
        if(agua_remanente < agua_minima){
            agua_remanente = agua_inicial;
            contador++;
        }
        cin >> perdida_agua;
    }
    cout << contador << endl;
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