#include<iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 1e9;
const long long int LLINF = 4e18;

int main(){
    set<char> vocales;
    vocales.insert('a');
    vocales.insert('e');
    vocales.insert('i');
    vocales.insert('o');
    vocales.insert('u');

    set<char> alf;
    alf.insert('.');
    alf.insert(',');
    alf.insert(';');
    
    while(true){
        int n;
        cin >> n;
        string po;
        getline(cin,po);
        if(n == 0) break;
        if(n > 4){
            cout << "DESCONOCIDO\n";
            string s;
            for(int i = 0; i < n; i++) getline(cin,s);
            continue;
        }
        string est[4];
        for(int i = 0; i < n && i < 4; i++){
            string s;
            getline(cin,s);
            transform(s.begin(),s.end(),s.begin(),::tolower);
            int cont=0;
            int ind;
            int d = 0;
            bool kk = true;
            for(int j = 0; j < s.length() && cont < 2; j++){
                if(!isalpha(s[s.length()-1-j]) && kk)d++;
                else kk = false;

                if(vocales.count(s[s.length()-1-j])) cont++;
                else if(s[s.length()-1-j] == ' '){
                    ind = s.length()-j;
                    break;
                }
                ind = s.length()-1-j;
            }
            est[i] = s.substr(ind,s.length()-ind-d);
        }
        if(n == 2){
            if(est[0] == est[1]) cout << "PAREADO\n";
            else cout << "DESCONOCIDO\n";
        }else if(n == 3){
            if(est[0] == est[2] && est[0] != est[1]) cout << "TERCETO\n";
            else cout << "DESCONOCIDO\n";
        }else if(n == 4){
            if(est[0] == est[3] && est[1] == est[2] && est[0] != est[1]) cout << "CUARTETO\n";
            else if(est[0] == est[2] && est[1] == est[3] && est[0] != est[1]) cout << "CUARTETA\n";
            else if(est[0] == est[1] && est[0] == est[2] && est[0] == est[3]) cout << "CUADERNA VIA\n";
            else if(est[0] != est[1] && est[0] != est[2] && est[0] != est[3] && est[1] != est[2] && est[1] != est[3] && est[2] != est[3]){
                for(int i = 0; i < 4; i++){
                    string c = "";
                    int cont = 0;
                    for(int j = 0; j < est[i].length() && cont < 2; j++){
                        if(vocales.count(est[i][j])) {
                            c+= est[i][j];
                            cont++;
                        }
                    }
                    est[i] = c;
                }
                if(est[0] != est[2] && est[0] != est[1] && est[1] == est[3]) cout << "SEGUIDILLA\n";
                else cout << "DESCONOCIDO\n";
            }else cout << "DESCONOCIDO\n";
        }else cout << "DESCONOCIDO\n";
    }
    return 0;
}