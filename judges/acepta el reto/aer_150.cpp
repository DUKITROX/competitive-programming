//---------------------------------------------------------
// Problema 150 ¡A dibujar hexágonos!
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int l;
    char c;
    cin >> l >> c;
	if (l == 0 && c == '0'){
        return false;
    }else{
        int lineas_a_dibujar = 2*l - 1;

        int contador_blancos = l - 1;
        int contador_negros = l;
        bool ascendente = true;

		for(int i = 0; i < lineas_a_dibujar; i++){
            for(int i = 0; i < contador_blancos; i++){
                cout << " ";
            }
            for(int i = 0; i < contador_negros; i++){
                cout << c;
            }
            cout << "" << endl;
            
            if(contador_blancos == 0){
                ascendente = false;
            }

            if(ascendente == true){
                contador_blancos--;
                contador_negros += 2;
            }else{
                contador_blancos++;
                contador_negros -= 2;
            }
        }
		return true;
	} // if-else marca de fin

} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main