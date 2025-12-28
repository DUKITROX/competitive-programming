#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int,int> cursos[10000];
const int feb = 29;

int  main(){
    while(true){
        int num;
        cin >> num;
        if(cin.fail()) break;

        string s1, s2;
        int horas, sec;
        int tot1,tot2;
        for(int i = 0; i < num; i++){
            tot1=0, tot2=0;
            cin >> s1 >> s2;
            if(s1.substr(3,2)=="02"){
                tot1+=31;
            }else if(s1.substr(3,2)=="03"){
                tot1+=31+feb;
            }else if(s1.substr(3,2)=="04"){
                tot1+=31+feb+31;
            }else if(s1.substr(3,2)=="05"){
                tot1+=31+feb+31+30;
            }else if(s1.substr(3,2)=="06"){
                tot1+=31+feb+31+30+31;
            }else if(s1.substr(3,2)=="07"){
                tot1+=31+feb+31+30+31+30;
            }else if(s1.substr(3,2)=="08"){
                tot1+=31+feb+31+30+31+30+31;
            }else if(s1.substr(3,2)=="09"){
                tot1+=31+feb+31+30+31+30+31+31;
            }else if(s1.substr(3,2)=="10"){
                tot1+=31+feb+31+30+31+30+31+31+30;
            }else if(s1.substr(3,2)=="11"){
                tot1+=31+feb+31+30+31+30+31+31+30+31;
            }else if(s1.substr(3,2)=="12"){
                tot1+=31+feb+31+30+31+30+31+31+30+31+30;
            }
            tot1 += stoi(s1.substr(0,2));

            if(s2.substr(3,2)=="02"){
                tot2+=31;
            }else if(s2.substr(3,2)=="03"){
                tot2+=31+feb;
            }else if(s2.substr(3,2)=="04"){
                tot2+=31+feb+31;
            }else if(s2.substr(3,2)=="05"){
                tot2+=31+feb+31+30;
            }else if(s2.substr(3,2)=="06"){
                tot2+=31+feb+31+30+31;
            }else if(s2.substr(3,2)=="07"){
                tot2+=31+feb+31+30+31+30;
            }else if(s2.substr(3,2)=="08"){
                tot2+=31+feb+31+30+31+30+31;
            }else if(s2.substr(3,2)=="09"){
                tot2+=31+feb+31+30+31+30+31+31;
            }else if(s2.substr(3,2)=="10"){
                tot2+=31+feb+31+30+31+30+31+31+30;
            }else if(s2.substr(3,2)=="11"){
                tot2+=31+feb+31+30+31+30+31+31+30+31;
            }else if(s2.substr(3,2)=="12"){
                tot2+=31+feb+31+30+31+30+31+31+30+31+30;
            }
            tot2 += stoi(s2.substr(0,2));

            cursos[i].first = tot2;
            cursos[i].second = tot1;
        }
        sort(cursos, cursos+num);
        int cont = 1, min = cursos[0].first;
        for(int i = 1; i < num; i++){
            if(cursos[i].second >= min){
                cont++;
                min = cursos[i].first;
            }
        }
        cout << cont << endl;
    }
    return 0;
}