//---------------------------------------------------------
// Problema 190 Dividir factoriales
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

    int num, den;
    cin >> num >> den;

	if (num < den)
		return false;
	else{
        int n = num - den;
        int m = den + 1;
        long long total = 1;

        for(int i = 0; i < n; i++){
            total = total * m;
            m++;
        }
        cout << total << endl;
		return true;
	}
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main