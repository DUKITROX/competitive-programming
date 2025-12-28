//---------------------------------------------------------
// Problema 164 Área de un rectangulo
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

	int base, altura;
	base = c3 - c1;
	altura = c4 -c2;

	if (base < 0 || altura < 0){
        return false;
    }else {
		cout << base*altura << endl;
        return true;
	}
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main