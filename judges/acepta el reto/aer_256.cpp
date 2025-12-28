#include <iostream>
using namespace std;

/*

TODO ESTO ES COMO YO LO HABIA INTENTADO, PERO COMO NO ME SALIA Y ME ESTABA ESTRESANDO LO POSPUSE PARA HACERLO DESPUES
Y LA SOLUCION QUE HE PUESTO ES DE INTERNET ;-;

bool is_number(const std::string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main(){
    while(true){
        string c1;
        cin >> c1;

        if(is_number(c1) == false){
            break;
        }else{
            string c2, c3;
            cin >> c2 >> c3;

            int digits_c1 = c1.length();
            int digits_c2 = c2.length();
            int digits_c3 = c3.length();
            bool def_c1 = false, def_c2 = false, def_c3 = false;
            int max_digits;
            bool ruido_cosmico = false;

            if(digits_c1 >= digits_c2 && digits_c1 >= digits_c3){
                max_digits = digits_c1;
                while(c2.length() != max_digits){
                    c2.insert(0,"0");
                    def_c2 = true;
                }
                while(c3.length() != max_digits){
                    c3.insert(0,"0");
                    def_3 = true;
                }

            }else if(digits_c2 >= digits_c1 && digits_c2 >= digits_c3){
                max_digits = digits_c2;
                while(c1.length() != max_digits){
                    c1.insert(0,"0");
                    def_c1 = true;
                }
                while(c3.length() != max_digits){
                    c3.insert(0,"0");
                    def_c3 = true;
                }

            }else{
                max_digits = digits_c3;
                while(c2.length() != max_digits){
                    c2.insert(0,"0");
                    def_c2 = true;
                }
                while(c1.length() != max_digits){
                    c1.insert(0,"0");
                    def_c1 = true;
                }
            }
            string d1, d2, d3;
            string numero_final;
            for(int i = 0; i < max_digits; i++){
                d1 = c1.back();
                d2 = c2.back();
                d3 = c3.back();

                if(def_c1 || def_c2 || def_c3){
                    if(d1 == d2 || d1 == d3 ){
                        numero_final.insert(0, d1);
                    }else if(d2 == d1 || d2 == d3){
                        numero_final.insert(0, d2);
                    }else if(d3 == d1 || d3 == d2){
                        numero_final.insert(0,d3);
                    }else{
                        cout << "RUIDO COSMICO" << endl;
                        ruido_cosmico = true;
                        break;
                    }
                }
                else if(d1 == d2 || d1 == d3){
                    numero_final.insert(0, d1);
                }else if(d2 == d1 || d2 == d3){
                    numero_final.insert(0, d2);
                }else if(d3 == d1 || d3 == d2){
                    numero_final.insert(0,d3);
                }else{
                    cout << "RUIDO COSMICO" << endl;
                    ruido_cosmico = true;
                    break;
                }
                c1.erase(c1.length() - 1);
                c2.erase(c2.length() - 1);
                c3.erase(c3.length() - 1);
            }
            if(ruido_cosmico == false){
                cout << numero_final << endl;
            }
        }
    }
    return 0;
}
*/
#include <iostream>
#include <cmath>

using namespace std;

bool solveCase();
unsigned long long int solve(unsigned long long int & a,
		unsigned long long int & b, unsigned long long int & c, bool & error);

int main() {
	while (solveCase())
		;
	return 0;
}

bool solveCase() {
	unsigned long long int a, b, c;
	bool error;
	cin >> a >> b >> c;
	if (!cin) {
		return false;
	}
	a = solve(a, b, c, error);
	if (error) {
		cout << "RUIDO COSMICO" << endl;
	} else {
		cout << a << endl;
	}
	return true;
}

unsigned long long int solve(unsigned long long int & a,
		unsigned long long int & b, unsigned long long int & c, bool & error) {
	error = false;
	unsigned long long int original = 0;
	int powerCounter = 0;
	while (a != 0 || b != 0 || c != 0) {
		if (a % 10 == b % 10 || a % 10 == c % 10) {
			original += (a % 10) * pow(10, powerCounter);
			powerCounter++;
		} else if (b % 10 == c % 10) {
			original += (b % 10) * pow(10, powerCounter);
			powerCounter++;
		} else {
			error = true;
			break;
		}
		a = a / 10;
		b = b / 10;
		c = c / 10;
	}
	return original;
}