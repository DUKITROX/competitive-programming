#include <iostream>
#include <map>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(!n) break;
        map<string,pair<bool, bool> >nombres;
        string s,sa;
        char c;
        int par = 0, inc = 0, sobr = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            c = s[s.length()-1];
            sa = s.substr(0,s.length()-1);
            if(nombres.find(sa) != nombres.end()){
                pair<bool,bool> p;
                p.first = false;
                p.second = false;
                pair<string, pair<bool, bool> > pa;
                pa.first = sa;
                pa.second = p;
                nombres.insert(pa);  
            }
            if(c == 'o'){
                if(nombres[sa].first){
                    sobr++;
                }else if(!nombres[sa].second){
                    inc++;
                }else{
                    inc--;
                    par++;
                }
                nombres[sa].first = true;
            }else if(c == 'a'){
                if(nombres[sa].second){
                    sobr++;
                }else if(!nombres[sa].first){
                    inc++;
                }else{
                    inc--;
                    par++;
                }
                nombres[sa].second = true;
            }
        }
        cout << par << " " << inc << " " << sobr << endl;
    }
    return 0;
}