#include <bits/stdc++.h>
using namespace std;

#define double long double

const double EPS = 1e-9;

int n, im, pa, bo, inv;
int bruh2 = 0;

struct glass{
	bool elim = false;
	int nivel, ind;
	double max, llevo=0.0L, flux;
	glass(int ni, int in, double ma, double fl) : nivel(ni), ind(in), max(ma), flux(fl){}
	glass(){}
};

int bruh = 0;
void anyadir(int nivel, int ind, double max, double flux, map<pair<int,int>, glass>& m, set<pair<int,int>>& s){
	if(!s.count({nivel,ind})){
		s.insert({nivel,ind});
		m[{nivel,ind}].nivel = nivel;
		m[{nivel,ind}].ind = ind;
		m[{nivel,ind}].max = max;
		m[{nivel,ind}].flux = flux;
	}else{
		if(m.find({nivel,ind}) == m.end() && flux > 0.599*(1e-4)){
			anyadir(nivel+1, ind, (nivel%2?pa:im), flux/2.0L, m, s);
			anyadir(nivel+1, ind+1, (nivel%2?pa:im), flux/2.0L, m, s);
		}else{
			m[{nivel,ind}].flux += flux;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> n >> im >> pa >> bo >> inv){

		map<pair<int,int>, glass> m; m[{1,1}].nivel = 1; m[{1,1}].ind = 1; m[{1,1}].max = im; m[{1,1}].flux = 1.0;
		set<pair<int,int>> s;

		int cont = 0;
		double litros = 0.0L;

		while(cont < inv){
			double tiempo = -1;
			for(auto e : m){
				if(tiempo == -1) tiempo = (e.second.max - e.second.llevo) / e.second.flux;
				else tiempo = min((e.second.max - e.second.llevo) / e.second.flux, tiempo);
			}

			litros += tiempo;

			for(auto& e : m){
				e.second.llevo += tiempo*e.second.flux;
			}

			auto it = m.begin();
			while(it != m.end()){
				if(it->second.llevo + EPS >= it->second.max && it->second.elim == false){
					cont++;
					pair<int,int> pos = it->first;

					anyadir(it->second.nivel+1, it->second.ind, (it->second.nivel%2?pa:im), it->second.flux/2.0L, m, s);
					anyadir(it->second.nivel+1, it->second.ind+1, (it->second.nivel%2?pa:im), it->second.flux/2.0L, m, s);

					it = m.erase(m.find(pos));
				}
				it++;
			}
		}
		cout << ((int)ceil(litros))/bo + ((int)ceil(litros))%bo << "\n";
	}
}
