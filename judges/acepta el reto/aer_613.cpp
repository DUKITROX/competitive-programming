//---------------------------------------------------------
// Problema 613 Unos
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <math.h>
using namespace std; 

bool casoDePrueba() {
    int n;
    cin >> n;
	if (cin.fail()){
        return false;
    }else{
        int contador = 1;
        int modulos = 1;
        while(modulos % n != 0){
            modulos = modulos % n;
            modulos = modulos*10 + 1;
            contador++;
        }
        cout << contador << endl;
        return true;
	}
}

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main