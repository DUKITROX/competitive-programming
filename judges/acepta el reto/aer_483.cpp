#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; i++){
        string camp_inicial, camp_final;
        int num_campanadas, campanada;
        cin >> camp_inicial >> camp_final >> num_campanadas >> campanada;

        int s1,s2, s_total;
        int s_campanada, s_final;

        s1 = stoi(camp_inicial.substr(0, 2))*60*60 + stoi(camp_inicial.substr(3,2))*60 + stoi(camp_inicial.substr(6,2));
        s2 = stoi(camp_final.substr(0, 2))*60*60 + stoi(camp_final.substr(3,2))*60 + stoi(camp_final.substr(6,2));

        if(s2 > s1){
            s_total = s2-s1;
        }else{
            s_total = 86400 - s1 + s2;
        }

        num_campanadas--, campanada--;
        s_campanada = s_total / num_campanadas;

        s_final = s_campanada * campanada + s1;
        s_final %= 86400;
        
        int h=0, m=0, z=0;

        h = s_final/3600;
        s_final %= 3600;

        m = s_final/60;
        s_final %= 60;

        z = s_final;

        cout << setfill('0') << setw(2) << h <<":"<< setfill('0') << setw(2) << m << ":"<< setfill('0') << setw(2) << z << endl;
    }
    return 0;
}