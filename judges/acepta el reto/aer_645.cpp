#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UFDS {
    vector<int>  p, setSize;
    int numSets;
    UFDS( int n ){
    p.assign(n, 0);
    setSize.assign(n, 1);
    numSets = n;
    for(int i = 0; i < n; i++)
        p[ i ] = i;
    }
    int find(int x){
        return(p[ x ] == x ? x : p[ x ] = find( p[ x ] ) );
    }
    void merge(int x, int y){
        int i = find(x), j = find(y);
	    if(i == j) return;
	    p[ i ] = j;
	    setSize[ j ] += setSize[ i ];
	    numSets--;
    }
    int size(int i){
        return setSize[ find( i ) ];
    }
};
int Kruskal(UFDS& nodes, vector<pair<int, pair<int,int> > >& edges){
    int minWeight = 0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++){
        if(nodes.find(edges[i].second.first-1) != nodes.find(edges[i].second.second-1)){
            nodes.merge(edges[i].second.first-1, edges[i].second.second-1);
            minWeight += edges[i].first;
        }
    }
    if(nodes.numSets != 1){
        minWeight = -1;
    }
    return minWeight;
}

int main(){
    while(true){
        int n, e;
        cin >> n;
        if(cin.fail()) break;
        else cin >> e;
        UFDS nodes(n);
        vector<pair<int, pair<int, int> > > edges(e);
        for(int i = 0; i < e; i++){
            cin >> edges[i].second.first;
            cin >> edges[i].second.second;
            cin >> edges[i].first;
        }
        int sol = Kruskal(nodes, edges);
        if(sol != -1) cout << sol << endl;
        else cout << "No hay puentes suficientes" << endl;
    }
    return 0;
}