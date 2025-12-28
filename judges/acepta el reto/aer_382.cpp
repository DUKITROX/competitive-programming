#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int c;
    cin >> c;
    while(c--){
        int ini = 0, fin, num;
        cin >> fin >> num;

        pair<int,int> metro[1000];
        int centro, longi;
        for(int i = 0; i < num; i++){ // cargando array de antenas
            cin >> centro >> longi;
            int n1 = centro-longi;
            int n2 = centro+longi;
            if(n1<0) n1 = 0;

            metro[i].first = n1;
            metro[i].second = n2;
        }
        sort(metro, metro+num);
        bool cubierto=true;
        if(metro[0].first > 0) cubierto = false;
        if(metro[num-1].second < fin) cubierto = false;
        for(int i = 0; i < num-1 && cubierto; i++){
            if(metro[i].second < metro[i+1].first-1) cubierto = false;
        }

        if(cubierto) cout << "SI\n";
        else cout << "NO\n";
    }
    return 0;
}