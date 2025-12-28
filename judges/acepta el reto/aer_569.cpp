#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int c = 0; c < casos; c++){
        int part, n, total=0;
        cin >> part >> n;

        string met;
        int dur_met, sec_met, ini = 0;
        for(int i = 0; i < n; i++){
            cin >> met >> dur_met;
            sec_met = (stoi(met.substr(0,2))-8)*60 + stoi(met.substr(3,2));
            if(sec_met - ini >= part) total += sec_met-ini;
            ini = sec_met+dur_met;
        }
        if(6*60-ini >= part) total += 6*60-ini;

        cout << total << endl;
    }
    return 0;
}