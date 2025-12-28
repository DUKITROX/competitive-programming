#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int horas, encendidos, uso;
		string msg;
		cin >> horas >> encendidos >> uso;
		
		int div = horas / uso;

		if(div < encendidos) msg = "HORAS";
		else if(div == encendidos) msg = "AMBAS";
		else msg = "ENCENDIDOS";

		cout << msg << endl;
	}
	return 0;
}
