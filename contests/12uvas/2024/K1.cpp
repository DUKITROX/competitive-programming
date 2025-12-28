#include <bits/stdc++.h>
using namespace std;

#define double long double

const double EPS = 1e-9;

struct glass{
	int nivel, ind;
	double max, llevo=0, flux;
	glass(int ni, int in, double ma, double fl) : nivel(ni), ind(in), max(ma), flux(fl){}
};

void anyadir(int nivel, int ind, double max, double flux, vector<glass>& arr){
	int pos = -1;
	for(int i = 0; i  < arr.size(); i++){
		if(arr[i].nivel == nivel && arr[i].ind == ind) pos = i;
	}

	if(pos == -1){
		glass gl(nivel, ind, max, flux);
		arr.push_back(gl);
	}else{
		arr[pos].flux += flux;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, im, pa, bo, inv;
	while(cin >> n >> im >> pa >> bo >> inv){

		vector<glass> arr; glass gl(1,1,im,1.0); arr.push_back(gl);

		int cont = 0;
		double litros = 0.0;

		while(cont < inv){
			cont++;
			sort(arr.begin(), arr.end(), [&](const glass& g1, const glass& g2)->bool{
				double v1 = (g1.max-g1.llevo)/g1.flux;
				double v2 = (g2.max-g2.llevo)/g2.flux;
				return v1+EPS < v2;
			});

			double tiempo = (arr[0].max-arr[0].llevo)/arr[0].flux;
			litros += tiempo;

			for(int i = 0; i < arr.size(); i++){
				double liquid = tiempo*arr[i].flux;
				arr[i].llevo += liquid;
			}

			anyadir(arr[0].nivel+1, arr[0].ind, (arr[0].nivel%2?pa:im), arr[0].flux/2.0, arr);
			anyadir(arr[0].nivel+1, arr[0].ind+1, (arr[0].nivel%2?pa:im), arr[0].flux/2.0, arr);

			arr.erase(arr.begin());
		}
		cout << ((int)ceil(litros))/bo + (((int)ceil(litros))>0)%bo << "\n";
	}
}
