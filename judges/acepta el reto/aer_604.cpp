//---------------------------------------------------------
// Problema 604 Honor y distribucion
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

void casoDePrueba() {

    int score = 0;
    int n_corazon = 0, n_diamantes = 0, n_picas = 0, n_treboles = 0;
    
	for (int i = 0; i < 26; i++){

        if(i%2 != 0 || i == 1){
            //palos (impar) puntos de DISTRIBUCION
            string tipo_de_palo;
            cin >> tipo_de_palo;

            //comprobar el tipo de palo y asignar
            if(tipo_de_palo == "C"){
                n_corazon++;
            }else if (tipo_de_palo == "D"){
                n_diamantes++;
            }else if (tipo_de_palo == "P"){
                n_picas++;
            }else if (tipo_de_palo == "T"){
                n_treboles++;
            }
        }else{
            //cartas (par) puntos de HONOR
            string tipo_de_carta;
            cin >> tipo_de_carta;

            if(tipo_de_carta == "A"){
                score += 4;
            }else if(tipo_de_carta == "K"){
                score += 3;
            }else if(tipo_de_carta == "Q"){
                score += 2;
            }else if(tipo_de_carta == "J"){
                score += 1;
            }
        }
    }
    //sumatorio de puntos de DISTRIBUCION
    int palos[4] = {n_corazon, n_diamantes, n_picas, n_treboles};
    for (int i = 0; i < 4; i++){
        if(palos[i] == 2){
            score +=1;
        }else if(palos[i] == 1){
            score += 2;
        }else if(palos[i] == 0){
            score += 3;
        }
    }
    cout << score << endl;
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