#include <bits/stdc++.h>
using namespace std;

#define double long double

const double EPS = 1e-9;

int n, im, pa, bo, inv;

struct glass{
	bool elim = false;
	int nivel, ind;
	double max, llevo=0.0L, flux;
	glass(int ni, int in, double ma, double fl) : nivel(ni), ind(in), max(ma), flux(fl){}
};

void anyadir(int nivel, int ind, double max, double flux, vector<glass>& arr, set<pair<int,int>>& s){
	int pos = -1;
	for(int i = 0; i  < arr.size(); i++){
		if(arr[i].nivel == nivel && arr[i].ind == ind) pos = i;
	}

	if(pos == -1){
		if(s.count({nivel,ind})){
			anyadir(nivel+1, ind, (arr[pos].nivel%2?pa:im), flux/2.0L, arr, s);
			anyadir(nivel+1, ind+1, (arr[pos].nivel%2?pa:im), flux/2.0L, arr, s);
		}else{
			glass gl(nivel, ind, max, flux);
			arr.push_back(gl);
			s.insert({nivel, ind});
		}
	}else{
		arr[pos].flux += flux;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> n >> im >> pa >> bo >> inv){
		
		int l = 1, r = 1e9, res = -1;
		while(l <= r){
			int m = (l+r)/2;
			double almax = bo*m;

			vector<glass> arr; glass gl(1,1,im,1.0L); arr.push_back(gl);
			set<pair<int,int>> s; s.insert({1,1});

			int cont = 0;
			double litros = 0.0L;

			while(cont < inv && almax >= 0){
				sort(arr.begin(), arr.end(), [&](const glass& g1, const glass& g2)->bool{
					double v1 = (g1.max-g1.llevo)/g1.flux;
					double v2 = (g2.max-g2.llevo)/g2.flux;
					return v1 < v2;
				});

				double tiempo = (arr[0].max-arr[0].llevo)/arr[0].flux;
				litros += tiempo;

				for(int i = 0; i < arr.size(); i++){
					double liquid = tiempo*arr[i].flux;
					arr[i].llevo += liquid;
					almax -= liquid;
				}

				auto it = arr.begin();
				while(it != arr.end()){
					if(it->llevo + EPS >= it->max){
						cont++;
						int pos = it - arr.begin();

						anyadir(arr[pos].nivel+1, arr[pos].ind, (arr[pos].nivel%2?pa:im), arr[pos].flux/2.0L, arr, s);
						anyadir(arr[pos].nivel+1, arr[pos].ind+1, (arr[pos].nivel%2?pa:im), arr[pos].flux/2.0L, arr, s);

						it = arr.erase(arr.begin()+pos);
					}else
						it++;
				}
			}

			if(almax>=0){
				res = m;
				r = m-1;
			}else
				l = m+1;
		}
		cout << res << "\n";
	}
}
