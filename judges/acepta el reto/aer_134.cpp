#include <iostream>
#include <algorithm>
using namespace std;

int stringTointeger(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
  
        // Since ASCII value of character from '0'
        // to '9' are contiguous. So if we subtract
        // '0' from ASCII value of a digit, we get 
        // the integer value of the digit.
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int,char> esc[4];
    while(true){
        string n;
        char c;
        cin >> n;
        if(n == "0") break;
        cin >> c;
        if(n == "J") n = "11";
        else if(n == "Q") n = "12";
        else if(n == "K") n = "13";
        else if(n == "A") n = "14";
        esc[0].first = stringTointeger(n);
        esc[0].second = c;
        for(int i = 1; i <= 3; i++){
            cin >> n >> c;
            if(n == "J") n = "11";
            else if(n == "Q") n = "12";
            else if(n == "K") n = "13";
            else if(n == "A") n = "14";
            esc[i].first = stringTointeger(n);
            esc[i].second = c;
        }

        sort(esc, esc+4);
        bool podemos = true;
        int saltos=0;
        int indice;
        for(int i = 0; i < 3 && podemos; i++){
            if(esc[i].second != esc[i+1].second) podemos = false;
            if(esc[i].first+2 == esc[i+1].first){
                saltos++;
                indice = i;
            }else if(esc[i].first+1 != esc[i+1].first) podemos = false;
        }
        if(saltos == 1 && podemos){
            if(esc[indice].first + 1 <= 10) cout << esc[indice].first+1 << " " << esc[indice].second << "\n";
            else{
                char kk;
                if(esc[indice].first == 10) kk = 'J';
                else if(esc[indice].first == 11)  kk = 'Q';
                else if(esc[indice].first == 12) kk = 'K';
                else if(esc[indice].first == 13) kk = 'A';
                cout <<kk << " " << esc[0].second << "\n";
            }
        }else if(saltos == 0 && podemos){
            if(esc[3].first == 14) {
                cout << esc[0].first-1 << " " << esc[0].second << "\n";
            }
            else {
                if(esc[3].first < 10) cout << esc[3].first+1 << " " << esc[0].second << "\n";
                else {
                    char kk;
                    if(esc[3].first == 10) kk = 'J';
                    else if(esc[3].first == 11)  kk = 'Q';
                    else if(esc[3].first == 12) kk = 'K';
                    else if(esc[3].first == 13) kk = 'A';
                    cout << kk << " " << esc[0].second << "\n";
                }
            }
        }else{
            cout << "NADA\n";
        }
    }
    return 0;
}