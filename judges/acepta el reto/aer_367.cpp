#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int c = 0; c < casos; c++){
        int ini, num;
        cin >> ini >> num;
        vector<int> portales;
        int aux;
        for(int i = 0; i < num; i++){
            cin >> aux;
            portales.push_back(aux);
        }
        sort(portales.begin(), portales.end());

        int distancia=5001, pos_min;
        for(int i = 0; i < num; i++){
            if(abs(portales[i]-ini) < distancia){
                distancia = abs(portales[i]-ini);
                pos_min = i;
            }else if(abs(portales[i]-ini)==distancia){
                if(portales[i] > portales[pos_min]) pos_min = i;
            }
        }
        cout << portales[pos_min] << " pos_min: " << pos_min << " ";
        int pos_left = pos_min-1, pos_right = pos_min+1;
        vector<int> visitados;
        for(int i = 0; i < num-1; i++){
            if(pos_min >= 0 && pos_right < num){
                cout << "d1: " << pos_min << " d2: " << portales[pos_right]-portales[pos_min] << " ;  ";
                if(portales[pos_min]-portales[pos_left] < portales[pos_right]-portales[pos_min]){
                    visitados.push_back(portales[pos_left]);
                    cout << portales[pos_left] << " ";
                    pos_min = pos_left;
                    pos_left--;
                }else{
                    visitados.push_back(portales[pos_right]);
                    cout << portales[pos_right] << " ";
                    pos_min = pos_right;
                    pos_right++;
                }
            }else{
                if(pos_min >= 0){
                    visitados.push_back(portales[pos_left]);
                    cout << portales[pos_left] << " ";
                    pos_left--;
                }else{
                    visitados.push_back(portales[pos_right]);
                    cout << portales[pos_right] << " ";
                    pos_right++;
                }
            }
        }
        cout << endl;
    }
    return 0;
}