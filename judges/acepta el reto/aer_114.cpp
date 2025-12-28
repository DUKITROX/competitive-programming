// Problema 114 Último digito factorial
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

void casoDePrueba() {

    int n;
    cin >> n;
    if (n == 0) cout << 1 << endl;
    else if (n <= 2) cout << n << endl;
    else if (n == 3) cout << 6 << endl;
    else if (n == 4) cout << 4 << endl;
   
    else cout << 0 << endl;
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