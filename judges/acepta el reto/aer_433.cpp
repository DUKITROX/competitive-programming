#include <iostream>
using namespace std;

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0) break;

		int contador = 1;
		while(n > 0){
			n -= contador;
			contador++;
		}
		cout << contador-1 << endl;
	}
	return 0;
}