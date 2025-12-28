//---------------------------------------------------------
// Problema 605 Ordenando el armario
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

//Todo este codigo es un asco y no hay quien lo entienda pero funciona, que es lo importante

int verano = 0, invierno = 0;
bool primer_caso = false;

bool casoDePrueba() {

    char estacion;
    cin >> estacion;

	if (estacion == '.'){
        if(primer_caso == true){
            if(verano > invierno){
                cout << "VERANO" << endl;
                verano = 0, invierno = 0;

            }else if(verano < invierno){
                cout << "INVIERNO" << endl;
                verano = 0, invierno = 0;

            }else if(verano == invierno){
                cout << "EMPATE" << endl;
                verano = 0, invierno = 0;
            }
        }

        cin >> estacion;
        if(estacion == '.'){
            return false;
        }else{
            if(estacion == 'V'){
                verano++;
            }else if(estacion == 'I'){
                invierno++;
            }
            primer_caso = true;
            return true;
        }
    }
	else {
        if(estacion == 'V'){
            verano++;
        }else if(estacion == 'I'){
            invierno++;
        }
        primer_caso = true;
		return true;
	}
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main