#include <iostream>
using namespace std;

int main() {
	while (true) {
		unsigned long long int sabor, grosor;
		cin >> sabor;
		if (cin.fail()) break;
		cin >> grosor;
		bool existe = false;
		unsigned long long int max_sabor = 0, min_grosor = 999999999999999999;
		while (true) {
			if (sabor == 0 && grosor == 0) break;
			if (sabor >= max_sabor && grosor <= min_grosor) {
				existe = true;
				max_sabor = sabor;
				min_grosor = grosor;
			}
			else if ((sabor > max_sabor && grosor >= min_grosor)) {
				existe = false;
				max_sabor = sabor;
			}
			else if ((grosor < min_grosor && sabor <= max_sabor)) {
				existe = false;
				min_grosor = grosor;
			}
			cin >> sabor >> grosor;
		}
		if (existe) cout << max_sabor << " " << min_grosor << endl;
		else cout << "NO HAY MEJOR" << endl;
	}
	return 0;
}