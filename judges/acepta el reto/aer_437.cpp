#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        string tiempo;
        cin >> tiempo;
        int horas = stoi(tiempo.substr(0,2));
        int minutos = stoi(tiempo.substr(3,5));
        int segundos = stoi(tiempo.substr(6,8));

        const int seg_por_dia = 86400;
        int seg_anuncio = horas*60*60 + minutos*60 + segundos;
        int seg_restantes = seg_por_dia - seg_anuncio;

        horas = seg_restantes/(60*60);
        seg_restantes -= horas*60*60;
        minutos = seg_restantes/60;
        seg_restantes -= minutos*60;

        cout << setw(2) << setfill('0') << horas << ":" << setw(2) << setfill('0') << minutos << ":" << setw(2) << setfill('0') << seg_restantes << endl;
    }
    return 0;
}