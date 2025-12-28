//---------------------------------------------------------
// Problema 217 ¿Qué lado de la calle?
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int numero;
    cin >> numero;
	if (numero == 0)
		return false;
	else {
		if(numero%2 == 0){
            cout <<"DERECHA"<<endl;
        }else{
            cout << "IZQUIERDA"<< endl;
        }
		return true;
	} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main