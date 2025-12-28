#include <vector>
#include <iostream>
using namespace std;

/*
DIJKSTRA
2 partes
(1)
actualizar todos los valores adyacentes al nodo en el que estamos
(2)
ir al nodo mas proximo
*/

int main(){
    while(true){
        int V, M;
        if(cin.fail()) break;
        int innerDist[10001];                                     //DISTANCIAS INTERNAS
        for(int i = 1; i <= V; i++) cin >> innerDist[i];
        int ini, fin, distan;
        cin >> M;
        vector<vector<pair<int,int> > > adyList(V+1);            // ADYLIST
        for(int i = 0; i < M; i++){
            cin >> ini >> fin >> distan;
            pair<int,int> pareja;
            pareja.first=fin;
            pareja.second=distan;
            adyList[ini].push_back(pareja);                 
        }
        vector<bool> visited(V+1);                              //VISITED
        vector<bool> dist(V+1, 2147483647);                     //DISTANCIAS FINALES
        visited[1]=true;
        dist[1]=0; //TODO: cuando acabe la ejecucion sumar la dist_inicial
        int actual=1;
        for(int h = 1; h < V+1; h++){
            for(pair<int,int> p : adyList[actual]){
                dist[p.first];
                dist[p.first] = p.second + innerDist[p.first];
            }
        }
    }
    return 0;
}