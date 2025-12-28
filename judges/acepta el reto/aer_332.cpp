//---------------------------------------------------------
// Problema 332 Pesando carretas
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

void casoDePrueba() {

    /*la suma mas alta es c1 + c2 siendo c1 el carro de mas peso y c5 el de menos (orden descendiente)
    la suma mas baja es c4 + c5

    sumando todas las parejas será como si multiplicaramos por 4 todos los carros
    -> sumatorio_parejas = 4*c1 + 4*c2 + 4*c3 + 4*c4 + 4*c5
    pues como vemos en esta lista, la suma de todas las parejas equivale a la expresion previa

        p1 = c1 + c2
        p2 = c1 + c3
        p3 = c1 + c4
        p4 = c1 + c5

        p5 = c2 + c3
        p6 = c2 + c4    NOTA: las parejas de carros en esta lista no estan ordenadas por peso,
        p7 = c2 + c4          sino que no siguen ningun orden en especifico.

        p8 = c3 + c4
        p9 = c3 + c5

        p10 = c4 + c5

    conociendo la suma máxima, la suma mínima y el total, podemos despejar c3

    sumatorio_parejas = 4*c1 + 4*c2 + 4*c3 + 4*c4 + 4*c5

    4*suma_maxima = 4*(c1 + c2) = 4*c1 + 4*c2 = 4*p1
    4*suma_minima = 4*(c4 + c5) = 4*c4 + 4*c5 = 4*p10

    sumatorio_parejas = 4*p1 + 4*c3 + 4*p10

    despejando

    sumatorio_parejas = 4*p1 + 4*c3 + 4*p10 ->
    -> 4*c3 = sumatorio_parejas - 4*p1 - 4*p10 ->
    -> c3 = (sumatorio_parejas - 4*p1 - 4*p10) / 4
    */

    int p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
    int c1, c2 ,c3, c4, c5;
    int sum_max, sum_min, sum_parejas;
    cin >> p10 >> p9 >> p8 >> p7 >> p6 >> p5 >> p4 >> p3 >> p2 >> p1;

    sum_parejas = p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 + p10;
    sum_max = p1;
    sum_min = p10;

    c3 = (sum_parejas - 4*sum_max - 4*sum_min) / 4; // ecuacion demostrada previamente en comentarios

    c1 = p2 - c3; //la segunda suma mas grande sera c1 + c3 = p2 -> c1 = p2 - c3
    c2 = p1 - c1; //despejando de la ec. de suma_maxima (p1 = c1 + c2)

    c5 = p9 - c3; //la segunda suma mas pequeña sera c5 + c3 = p9 -> c5 = p9 - c3
    c4 = p10 - c5; //despejando de la ec. de suma_minima (p19 = c4 + c5)
    
    cout << c1 << " " << c2 << " " << c3 << " " << c4 << " " << c5 << endl;
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