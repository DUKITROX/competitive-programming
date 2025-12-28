//---------------------------------------------------------
// Problema 241 Me quiere, no me quiere
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

	int n;
    cin >> n;

    if(n < 3 || n == 5){
        cout << "IMPOSIBLE" << endl;
    }else if(n / 3 > 0){
        int t3, t4, h_restantes;

        t3 = n / 3;
        h_restantes = n % 3;

        if(h_restantes == 0){
            cout << 0 << endl;
        }else if(h_restantes == 1){
            cout << 1 << endl;
        }else if(h_restantes == 2){
            cout << 2 << endl;
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