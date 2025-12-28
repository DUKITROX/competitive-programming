#include <iostream>
using namespace std;

int main() {
    int anterior, siguiente, suma;
    while(1) {
        cin >> anterior;
        if(anterior < 0)
            return 0;
        suma = 0;
        while(1) {
            cin >> siguiente;
            if(siguiente == -1)
                break;
            suma = suma + abs(anterior-siguiente);
            anterior = siguiente;
        }
        cout << suma << endl;
    }
    return 0;
}