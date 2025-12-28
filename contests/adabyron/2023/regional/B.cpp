#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
using pii = pair<int,int>;

int N = 103;
int n = 4*N*N+2;

void dijkstra(int s, vector<int>& d, vector<vector<pair<int,int> > >& adj){
	int n = adj.size();
	d.assign(n, INF);
	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if(d_v != d[v]) continue;

		for(auto edge : adj[v]){
			int to = edge.first;
			int len = edge.second;

			if(d[v] + len < d[to]){
				d[to] = d[v] + len;
				q.push(make_pair(d[to], to));
			}
		}
	}
}

int node(int x, int y){ // dados unas coordenadas devuelve su representacion en el grafo
	return 4*(N*x + y);
} 

void solve(){
	vector<vector<pair<int,int > > >AL(n);
	vector<int> d(n);
	
	//SOURCE
	int x,y, ini = n-2, fin = n-1;
	cin >> x >> y;
	x += 51; y += 51;
	for(int i = 0; i < 4; i++){	
		int v = node(x,y)+i; 
		AL[ini].push_back(make_pair(v, 0));
	}
	//TARGET
	cin >> x >> y;
	x += 51; y += 51;
	for(int i = 0; i < 4; i++){ 
		int v = node(x,y)+i;
		AL[v].push_back(make_pair(fin,0));
	}

	//TRAPS
	set<int> s;
	int D;
	cin >> D;
	for(int i = 0; i < D; i++){
		cin >> x >> y; 
		x += 51; y += 51;
		s.insert(node(x,y));	
	}

	//GRAPH
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int v = node(i,j);
			if(!s.count(v)){
				//GIROS
				AL[v].push_back(make_pair(v+1, 4));
				AL[v].push_back(make_pair(v+3, 4));

				AL[v+1].push_back(make_pair(v+2, 4));
				AL[v+1].push_back(make_pair(v, 4));

				AL[v+2].push_back(make_pair(v+1, 4));
				AL[v+2].push_back(make_pair(v+3, 4));

				AL[v+3].push_back(make_pair(v, 4));
				AL[v+3].push_back(make_pair(v+2, 4));
				
				//PASOS NORTE-SUR ESTE-OESTE (coste 0)
				AL[v].push_back(make_pair(v+2,0));
				AL[v+2].push_back(make_pair(v,0));

				AL[v+1].push_back(make_pair(v+3,0));
				AL[v+3].push_back(make_pair(v+1,0));
	
				//CONECTARLO CON LAS 4 CELDAS ADYACENTES
				if(i-1 >= 0) AL[v+1].push_back(make_pair(node(i-1,j) + 3, 1));
				if(j+1 < N) AL[v+2].push_back(make_pair(node(i,j+1), 1));
				if(i+1 < N) AL[v+3].push_back(make_pair(node(i+1, j) + 1, 1));
				if(j-1 >= 0) AL[v].push_back(make_pair(node(i,j-1) + 2, 1));
			}	
		}
	}
	dijkstra(ini, d, AL);
	cout << (d[fin] == INF ? -1 : d[fin]) << "\n";
}

int main(){
	int casos;
	cin >> casos;
	while(casos--) solve();
}
