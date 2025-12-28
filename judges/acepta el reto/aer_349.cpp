#include <iostream>
using namespace std;

int notPol(){
    char c;
    cin >> c;
    int n1,n2;
    if(c == '+'){
        n1 = notPol();
        n2 = notPol();
        return n1+n2; 
    }else if(c == '-'){
        n1 = notPol();
        n2 = notPol();
        return n1 - n2;
    }else if(c == '*'){
        n1 = notPol();
        n2 = notPol();
        return n1*n2;
    }else if(c == '/'){
        n1 = notPol();
        n2 = notPol();
        return n1/n2;
    }else return c-48;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        cout << notPol() << endl;
    }
}