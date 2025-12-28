#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(cin >> n >> m && n+m){
        string s;
        int cont = 0;
        for(int i = 0; i < m; i++){
            cin >> s;
            for(int j = 0; j < n; j++){
                if(s[j] == '/' || s[j] == 92){
                    j++; cont++;
                    while(s[j] == '.' && j < n){
                        j++;
                        cont++;
                    }
                }
            }
        }
        cout << cont << "\n";
    }
}