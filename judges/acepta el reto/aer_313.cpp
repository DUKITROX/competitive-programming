//---------------------------------------------------------
// Problema 313 Fin de mes
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

	int s1, s2, dinero;
    cin >> s1 >> s2;
    dinero = s1+s2;
    if(dinero<0){
        cout << "NO" << endl;
    }else{
        cout << "SI" << endl;
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