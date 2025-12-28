//---------------------------------------------------------
// Problema 165 Número hyperpar
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
	if (n < 0)
		return false;
	else {
        int n_digitos = to_string(n).length();
        bool hyper_par = true;
        for(int i = 0; i < n_digitos; i++){
            if((n % 10) % 2 == 0){
                n = n / 10;
            }else{
                hyper_par = false;
            }
        }
        if(hyper_par){
            cout << "SI" << endl;
        }else{
            cout << "NO" << endl;
        }
		return true;
	}
} // casoDePrueba

//---------------------------------------------------------

int main() {

	while (casoDePrueba()) {
	}

	return 0;

} // main