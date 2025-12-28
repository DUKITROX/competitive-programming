//---------------------------------------------------------
// Problema 359 Timo en el cocedero de mariscos
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

    int contador_mejillones = 0, contador_conchas = 0;
    while(n != -1){
        contador_mejillones += n;
        contador_conchas++;
        cin >> n;
    }
    if(contador_conchas < contador_mejillones){
        cout << "Suerte" << endl;
    }else if(contador_conchas > contador_mejillones){
        cout << "Timo" << endl;
    }else{
        cout << "Justo" << endl;
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