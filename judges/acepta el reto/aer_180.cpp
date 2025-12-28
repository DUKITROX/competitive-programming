//---------------------------------------------------------
// Problema 180 Triángulos
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

#define PI 3.1415926535

void casoDePrueba() {
    //lados
    int a, b, c, A, B, C;
    cin >> a >> b >> c;

    if(a + b > c && a + c > b && b + c > a){
        A = (b*b+c*c-a*a);
        B = (a*a+c*c-b*b);
        C = (a*a+b*b-c*c);

        if(A == 0 || B == 0 || C == 0){
            cout << "RECTANGULO" << endl;
        }else if(A > 0 && B > 0 && C > 0){
            cout << "ACUTANGULO" << endl;
        }else if(A < 0 || B < 0 || C < 0){
            cout << "OBTUSANGULO" << endl;
        }
    }else{
        cout << "IMPOSIBLE" << endl;
    }
}
//---------------------------------------------------------

int main() {

	unsigned int numCasos, i;

	cin >> numCasos;

	for (i = 0; i < numCasos; ++i) {
		casoDePrueba();
	}

	return 0;

} // main