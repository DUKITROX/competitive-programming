//---------------------------------------------------------
// Problema 462 Mundo limpio
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void casoDePrueba() {

	// TU C�DIGO AQU�
    int numero_limpiezas, horas, minutos, segundos, horas_finales, minutos_finales, segundos_finales;
    long long segundos_totales, dias_finales;
    string tiempo_limpieza;
    
    cin >> numero_limpiezas >> tiempo_limpieza;

    //leer los datos del tiempo que permanecen limpias las gafas y transformar dichos datos en entero separando horas de minutos y de segundos
    horas = stoi(tiempo_limpieza.substr(0,2));
    minutos = stoi(tiempo_limpieza.substr(3,2));
    segundos = stoi(tiempo_limpieza.substr(6,2));

    //calcular el numero total de segundos que han permanecido limpias las gafas
    segundos_totales = horas*3600 + minutos*60 + segundos;
    segundos_totales = segundos_totales * numero_limpiezas;//problema: si no declaras "segundos:totales" como "long long",
                                                           //el resultado viene a ser un desbordamiento.

    //formatear correctamente en D HH:MM:SS el tiempo que han permanecido limpias las gafas
    dias_finales = segundos_totales/(3600*24);
    horas_finales = (segundos_totales - dias_finales*3600*24) / 3600;
    minutos_finales = ((segundos_totales - dias_finales*3600*24) % 3600) / 60;
    segundos_finales = segundos_totales - dias_finales*3600*24 - horas_finales*3600 - minutos_finales*60;

    //mostrar resultado por pantalla y bien formateado
    cout << dias_finales << " " << setw(2) << setfill('0') << horas_finales << ":" << setw(2) << setfill('0') << minutos_finales << ":" << setw(2) << setfill('0') << segundos_finales << endl;

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