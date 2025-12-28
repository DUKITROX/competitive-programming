#include <iostream>
using namespace std;

int covid(int n, string s){
    int res = 1;
    int ceil;
    if(n%2==1) ceil = n/2+1;
    else ceil = n/2;

    string s1 = s.substr(0,ceil);
    if(n == 1){
        
    }else{
        for(int i = 0; i < s1.length(); i++){
            if(s1[i]=='1'){
                res++;
                res+=covid(s1.length(), s1);
                break;
            }
        }
        string s2 = s.substr(ceil, n/2);
        for(int i = 0; i < s2.length(); i++){
            if(s2[i] == '1'){
                res++;
                res+=covid(s2.length(), s2);
                break;
            }
        }
    }
    return res;
}

int main(){
    while(true){
        int n;
        string s;
        cin >> n;
        if(n == 0) break;
        cin >> s;
        cout << covid(n,s) << endl;
    }
    return 0;
}