//---------------------------------------------------------
// Problema 147 Las 15 cerillas
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int cerillas_total, cerillas_turno;
    cin >> cerillas_total;
	if (!cin)
		return false;
	else {
		cin >> cerillas_turno;
        int controlador = cerillas_turno + 1;
        if((cerillas_total - 1) % controlador == 0){
            cout << "PIERDO" << endl;
        }else{
            //no se muy bien que hace eso, pero la info la saque de aqui
            //https://www.xatakaciencia.com/matematicas/como-ganar-siempre-al-juego-de-las-cerillas
            int contador = (cerillas_total - 1) / controlador;
            int resultado = cerillas_total - controlador * contador - 1;

            cout << resultado << endl;
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