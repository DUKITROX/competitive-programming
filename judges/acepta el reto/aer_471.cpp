//---------------------------------------------------------
// Problema 471 Buscando el pinchazo
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

int sumador_180(int k){
    k += 180;
    if(k > 360){
        k = k - 360;
    }
    return k;
}
void casoDePrueba() {

    int inicial, pinchazo;
    cin >> inicial >> pinchazo;

    if(inicial == pinchazo || sumador_180(inicial) == sumador_180(pinchazo) || inicial == sumador_180(pinchazo) || sumador_180(inicial) == pinchazo){
        cout << "DA IGUAL" << endl;
    }else{
        if(pinchazo < inicial){
            if(inicial - pinchazo < 180){
                cout << "DESCENDENTE" << endl;
            }else{
                cout << "ASCENDENTE" << endl;
            }
        }else{
            if(pinchazo - inicial < 180){
                cout << "ASCENDENTE" << endl;
            }else{
                cout << "DESCENDENTE" << endl;
            }
        }
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