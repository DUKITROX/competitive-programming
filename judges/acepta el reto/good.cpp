#include <iostream>
#include <vector>
#include <numeric>
#include <set>

// Función para calcular la suma de los cubos de los dígitos de un número.
// Por ejemplo, para 123, devuelve 1^3 + 2^3 + 3^3 = 1 + 8 + 27 = 36.
int suma_cubos_digitos(int n) {
    int suma = 0;
    while (n > 0) {
        int digito = n % 10;
        suma += digito * digito * digito;
        n /= 10;
    }
    return suma;
}

int main() {
    // Optimiza la entrada/salida estándar en C++
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int numero_inicial;
    // Lee números hasta que se introduzca un 0.
    while (std::cin >> numero_inicial && numero_inicial != 0) {
        
        // Imprime el número original con el que comienza la secuencia.
        std::cout << numero_inicial;

        long long n = numero_inicial;
        
        // Un 'set' para guardar los números que ya han aparecido en la secuencia
        // y así detectar ciclos de forma eficiente.
        std::set<long long> vistos;

        // El bucle continúa mientras no lleguemos a 1 y no repitamos un número.
        while (n != 1 && vistos.find(n) == vistos.end()) {
            vistos.insert(n); // Añade el número actual al conjunto de vistos.
            n = suma_cubos_digitos(n); // Calcula el siguiente número de la secuencia.
            std::cout << " - " << n; // Imprime el nuevo número.
        }

        // Comprueba la razón por la que el bucle terminó.
        if (n == 1) {
            std::cout << " -> cubifinito.\n";
        } else {
            // Si n != 1, es porque se encontró un número repetido (un ciclo).
            std::cout << " -> no cubifinito.\n";
        }
    }

    return 0;
}
