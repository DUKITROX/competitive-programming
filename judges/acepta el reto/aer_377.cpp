#include <iostream>
using namespace std;

int casos(){
    while(true){
        string n;
        cin >> n;
        int num;
        if(cin.fail()) return 0;
        else{
            if(n.length() <= 4){
                num = stoi(n);
            }else{
                num = stoi(n.substr(n.size()-4, 4));
            }
            num %= 16;
            if(num == 0 || num == 1 || num == 4 || num == 9) cout << "NO SE" << endl;
            else cout << "IMPERFECTO" << endl;
        }
    }
}

int main(){
    while(casos());
    return 0;
}