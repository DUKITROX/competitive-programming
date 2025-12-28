//---------------------------------------------------------
// Problema <num> <Titulo>
//
// https://www.aceptaelreto.com
//
// <Tu nombre aqu�>
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

    int c1, c2;
    cin >> c1 >> c2;
	if (c1 < 0 || c2 < 0){
        return false;
    }else{
        cout << c1*2 + c2*2 << endl;
        return true;
    }
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main