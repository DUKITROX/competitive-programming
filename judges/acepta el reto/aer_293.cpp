//---------------------------------------------------------
// Problema 293 Artrópodos
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
    int insectos, aracnidos, crustaceos, escolopendras, n_anillos_escolopendras;
    cin >> insectos >> aracnidos >> crustaceos >> escolopendras >> n_anillos_escolopendras;
    // insectos 6, arácnidos 8, crustáceos 10 y escolopendras 2*anillos

    cout << insectos*6 + aracnidos*8 + crustaceos*10 + escolopendras*2*n_anillos_escolopendras << endl;

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