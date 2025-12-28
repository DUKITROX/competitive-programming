#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
short int jugadores[100000];
int main(){
    while(true){
        int n,m,aux;
        cin >> n;
        if(!cin) break;
        cin >> m;

        map<int,int> tallas;

        for(int i = 0; i < n; i++) cin >> jugadores[i];
        for(int i = 0; i < m; i++){
            cin >> aux;
            if(tallas.find(aux) == tallas.end()){
                tallas[aux] = 1;
            }else{
                tallas[aux]++;
            }
        }
        sort(jugadores, jugadores+n);
        int cont = 0;
        for(int i = 0; i < n; i++){
            if(tallas[jugadores[i]] > 0){
                tallas[jugadores[i]]--;
            }else if(tallas[jugadores[i]+1] > 0){
                tallas[jugadores[i]+1]--;
            }else cont++;
        }
        cout << cont << endl;
    }
    return 0;
}