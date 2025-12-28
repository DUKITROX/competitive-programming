//---------------------------------------------------------
// Problema 304 División Euclidia
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

    int D, d = 0, c, r;
    bool div0 = false;
    cin >> D >> d;

    if(d == 0){
        cout << "DIV0" << endl;
        div0 = true;

    }else if(D > 0 && d > 0){
        c = D/d;
        r = D%d;
    }else if(D > 0 && d < 0){
        c = D/d;
        r = D%d;
    }else if(D < 0 && d > 0){
        if(D%d == 0){
            c = D/d;
            r = 0;
        }else{
            c = D/d - 1;
            r = (d*c - D)*(-1);
        }           
    }else{
        if(D%d == 0){
            c = D/d;
            r = 0;
        }else{
            c = D/d + 1;
            r = (d*c - D)*(-1);
        }
    }

    if(div0 == false){
        cout << c << " " << r << endl;
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