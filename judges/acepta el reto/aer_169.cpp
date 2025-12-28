#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    cin >> c;
    while(c--){
        string s;
        int cont = 0, her = 0;
        set<string> apellidos;
        set<string> ex;
        while(true){
            cin >> s;
            if(s != "===="){
                cont++;
                transform(s.begin(),s.end(),s.begin(),::tolower);
                if(ex.count(s)){
                    her++;
                }else if(apellidos.count(s)){
                    her += 2;
                    ex.insert(s);
                }else{
                    apellidos.insert(s);
                }
                cin >> s;
            }else{
                cout << cont << " " << her << "\n";
                break;
            }
        }
    }
    return 0;
}