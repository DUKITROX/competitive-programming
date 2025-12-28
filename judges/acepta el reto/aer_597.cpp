#include <iostream>
#include <vector>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int c = 0; c<casos; c++){
        int num;
        cin >> num;
        vector<int> numeros(num);
		for (int i = 0; i < num; ++i) cin >> numeros[i];
		int colados = 0;
		int minimo = 1000000;
		for (int i = num - 1; i >= 0; i--) {
			if (numeros[i] > minimo) colados++;
			minimo = min(minimo, numeros[i]);
		}
        cout << colados << endl;
    }
    return 0;
}