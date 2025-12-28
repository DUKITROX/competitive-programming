//---------------------------------------------------------
// Problema 130 Mejor... imposible
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {
	int baldosas;
    cin >> baldosas;
	if (baldosas == 0){
        return false;
    }
	else{
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        /*
        imaginaremos el tablero de baldosas como uno de ajedrez, de esto modo diremos que el 
        personaje se comporta como un "alfil", es decir, solo se puede mover por las casillas
        de su mismo color. Esto nos ayudará a saber si el movimiento a la casilla final es posible o no.
        dividermos el tablero en casillas negras y blancas (como en el ajedrez) sumando sus coordenadas,
        par = "negro"
        impar = "blanco"
        */

       if((x1 + y1) % 2 == (x2 + y2) % 2){

            bool condicion_diagonal_descendiente = false, condicion_diagonal_ascendente = false;
            if(x1+y1 == x2+y2){
                condicion_diagonal_descendiente = true;
            }
            if(x2 - x1 == y2 - y1){
                condicion_diagonal_ascendente = true;
            }

            
            if(x1 == x2 && y1 == y2){
                cout << 0 << endl;
            }
            else if(condicion_diagonal_descendiente == true || condicion_diagonal_ascendente == true){
                  cout << 1 << endl;
            }else{
                cout << 2 << endl;
            }

       }else{
           cout << "IMPOSIBLE" << endl;
       }
		return true;
	}
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main