//---------------------------------------------------------
// Problema 158 Los saltos de Mario
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {
    int muros;
    cin >> muros;

    int ascendente = 0, descendente = 0;
    int muro_actual, muro_siguiente;
    cin >> muro_actual;

    for(int i = 0; i < (muros - 1); i++){
        cin >> muro_siguiente;
        if(muro_actual < muro_siguiente){
            ascendente++;
        }else if(muro_actual > muro_siguiente){
            descendente++;
        }
        muro_actual = muro_siguiente;
    }
    cout << ascendente << " " << descendente << endl;
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