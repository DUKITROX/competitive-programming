#include <iostream>
using namespace std;

unsigned long long  stringTointeger(string str)
{
    unsigned long long int temp = 0;
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
    while(true){
        int n;
        cin >> n;
        if(n == 1){
            cout << "SI\n";
            continue;
        }
        if(n == 0) break;
        unsigned long long int a = n*n;
        string s = to_string(a);
        bool si=false;
        //cout << a << endl;
        for(int i = 0; i < s.length() && !si; i++){
            unsigned long long int d=0,b=0;
            d = stringTointeger(s.substr(0,i));
            b = stringTointeger(s.substr(i,s.length()-i));
            //cout << d << " + " << b << " = " << d+b << endl;
            if(d+b == n && b != 0) si = true;
        }
        if(si) cout << "SI\n";
        else cout << "NO\n";
    }
    return 0;
}