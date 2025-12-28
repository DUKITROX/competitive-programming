//---------------------------------------------------------
// Problema 239 Pi. Pi. Pi. Pi. Pi. Piiiii
//
// https://www.aceptaelreto.com
//
// <Tu nombre aqu�>
//---------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

bool casoDePrueba() {

	int dias, emisoras;
    cin >> dias >> emisoras;
	if (dias == 0 && emisoras == 0){
        return false;
    }else{

        int segundos_silencio = dias * 24 * 6 * emisoras;

        int dias, horas, minutos, segundos;

        dias = segundos_silencio/(3600*24);
        horas = (segundos_silencio - dias*3600*24) / 3600;
        minutos = ((segundos_silencio - dias*3600*24) % 3600) / 60;
        segundos = segundos_silencio - dias*3600*24 - horas*3600 - minutos*60;

        cout << dias << ":" << setw(2) << setfill('0') << horas << ":" << setw(2) << setfill('0') << minutos << ":" << setw(2) << setfill('0') << segundos << endl;

        return true;    
    }
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main