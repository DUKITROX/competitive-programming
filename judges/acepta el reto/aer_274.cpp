//---------------------------------------------------------
// Problema 274 Semanas
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

    int dias_ano, dias_semana, dia_inicial, n_semanas;
    cin >> dias_ano >> dias_semana >> dia_inicial;

	if (dia_inicial == 1){
		n_semanas = dias_ano / dias_semana; //dividimos los dias del año entre los dias por semana,
											//pues sabemos que el año empieza en el primer dia de la semana
	}else{
		dia_inicial--;
    	dias_ano = dias_ano - dias_semana + dia_inicial; // eliminamos los dias incompletos del principio del año
		n_semanas = dias_ano / dias_semana;
	}

    cout << n_semanas << endl;
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