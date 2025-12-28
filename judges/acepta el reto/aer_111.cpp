#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        string s;
        cin >> s;
        if(s == "Exit") break;
        int n;
        cin >> n;
        if(n==0) cout << "1s0\n";
        for(int i = 0; i < 4 && n; i++){
            for(int j = 0; j < 2 && n; j++){
                if(i == 0){
                    if(n > 2) {
                        cout << j+1 << "s2 ";
                        n -= 2;
                    }
                    else {
                        cout << j+1 << "s" << n << endl;
                        n = 0;
                    }
                }else if(i == 1){
                    if(n > 6){
                        cout << j+2 << "p6 ";
                        n-=6;
                        if(n > 2) {
                            cout << j+3 << "s2 ";
                            n-=2;
                        }
                        else {
                            cout << j+3 << "s" << n << endl;
                            n=0;
                        }
                    }
                    else {
                        cout << j+2 << "p" << n << endl;
                        n=0;
                    }
                }else if(i == 2){
                    if(n > 10) {
                        cout << j+3 << "d10 ";
                        n-=10;
                        if(n > 6){
                            cout << j+4 << "p6 "; 
                            n-=6; 
                            if(n > 2) {
                                cout << j+5 << "s2 ";
                                n-=2;
                            }
                            else {
                                cout << j+5 << "s" << n << endl;
                                n=0;
                            }
                        }
                        else {
                            cout << j+4 << "p" << n << endl;
                            n=0;
                        }
                    }else {
                        cout << j+3 << "d" << n << endl;
                        n=0;
                    }
                }else{
                    if(n > 14){
                        cout << j+4 << "f14 ";
                        n -= 14;
                        if(n > 10) {
                            cout << j+5 << "d10 ";
                            n -= 10;
                            if(n > 6){
                                cout << j+6 << "p6 ";  
                                n -= 6;
                                if(n > 2){
                                     cout << j+7 << "s2 ";
                                     n-=2;
                                }
                                else {
                                    cout << j+7 << "s" << n << endl;
                                    n = 0;
                                }
                            }
                            else {
                                cout << j+6 << "p" << n << endl;
                                n=0;
                            }
                        }else {
                            cout << j+5 << "d" << n << endl;
                            n=0;
                        }
                    }else {
                        cout << j+4 << "f" << n << endl;
                        n=0;
                    }
                }
            }
        }
    }
    return 0;
}