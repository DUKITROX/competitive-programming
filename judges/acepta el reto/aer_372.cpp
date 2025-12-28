#include <iostream>
#include <string>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        string p;
        bool mayus=false;
        cin >> p;
        if(isupper(p[0])){
            p[0]+=32;
            mayus = true;}

        int l = p.length();
        for(int i = 0; i < l/2; i++){
            swap(p[i], p[l-1-i]);
        }
        if(mayus)p[0]-=32;
        cout << p << endl;
    }
    return 0;
}