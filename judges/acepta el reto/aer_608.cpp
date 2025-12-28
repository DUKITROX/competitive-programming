//---------------------------------------------------------
// Problema 608 Peligro por hielo
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

	int numero, temperatura, temperatura_anterior, numero_avisos = 0;
	bool aviso = false;
	cin >> numero;
	if (numero == 0){
		return false;
	}
	else {
		//CODIGO PRINCIPAL

		//iteramos por cada entrada de temperatura
		for(int i = 0; i < numero; i++){
			cin >> temperatura;

		/*si todavia no ha habido ningun aviso, nos da igual que haya
		tenido que haber un dato de temperatura superior a 6*/
			if(aviso == false){
				if(temperatura <= 4){
					numero_avisos++;
					aviso = true;
				}
			}else{

		//reseteamos el aviso para que pueda emitir otro avisa pues un dato ha superado los 6 grados
				if(temperatura > 6){
					aviso = false;
				}
			}
		}
		cout << numero_avisos << endl;
		return true;
	}
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main