#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int casos;
    cin >> casos;
    while(casos--){
        int n, sum=0,cont=0;
        string s;
        cin >> n >> s;
        int ind = 0;
        for(int i = 0; i < s.length(); i++){
            sum += s[i]-48;
            if(sum == n){
                cont++;
                sum -= s[ind]-48;
                ind++;
            }
            if(sum > n){
                while(sum > n){
                    sum -= s[ind]-48;
                    ind++;
                }
            }
        }
        cout << cont << endl;
    }
    return 0;
}