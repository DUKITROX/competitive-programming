//---------------------------------------------------------
// Problema 300 Palabras pentavolcanicas
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

void casoDePrueba() {

    string palabra;
    cin >> palabra;
    if(palabra.find("a") == -1 || palabra.find("e") == -1 || palabra.find("i") == -1 || palabra.find("o") == -1 || palabra.find("u") == -1){
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