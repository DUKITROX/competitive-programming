//---------------------------------------------------------
// Problema 149 San Fermines
//
// https://www.aceptaelreto.com
//
// Daniel Bordeianu
//---------------------------------------------------------

#include <iostream>
using namespace std;

bool casoDePrueba() {

    int n;
    cin >> n;
    if(cin.fail()){
        return false;
    }else{
        int velocidad_max = 0;

        for(int i = 0; i < n; i++){
            int velocidad;
            cin >> velocidad;
            if(velocidad >= velocidad_max){
                velocidad_max = velocidad;
            }
        }
        cout << velocidad_max << endl;
		return true;
    }
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main