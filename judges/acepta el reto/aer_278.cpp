//---------------------------------------------------------
// Problema 278 El baile de Cenicienta
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int calculador_de_tiempos_horas(string tiempo){
    //leer los datos del tiempo
    int horas = stoi(tiempo.substr(0,2));
    int minutos = stoi(tiempo.substr(3,2));
    int segundos = stoi(tiempo.substr(6,2));

    //calcular el numero total de segundos
    int segundos_totales = horas*3600 + minutos*60 + segundos;
    return segundos_totales;
}
int calculador_de_tiempos_dias(string tiempo){
    //leer los datos del tiempo
    int dias = stoi(tiempo.substr(0,2));
    int horas = stoi(tiempo.substr(3,2));
    int minutos = stoi(tiempo.substr(6,2));
    int segundos = stoi(tiempo.substr(9,2));

    //calcular el numero total de segundos
    int segundos_totales = dias*86400 + horas*3600 + minutos*60 + segundos;
    return segundos_totales;
}

void casoDePrueba() {

	string tiempo_fiesta, tiempo_tarea;
    cin >> tiempo_fiesta >> tiempo_tarea;

    int tiempo_tareas_total = 0;
    int t_fiesta = calculador_de_tiempos_dias(tiempo_fiesta);

    while(calculador_de_tiempos_horas(tiempo_tarea) != 0){
        tiempo_tareas_total += calculador_de_tiempos_horas(tiempo_tarea);
        cin >> tiempo_tarea;
    }
    if(tiempo_tareas_total < t_fiesta){
        cout << "SI" << endl;
    }else{
        cout << "NO" << endl;
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