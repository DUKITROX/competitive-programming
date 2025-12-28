#include <iostream>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int n;
        cin >> n;
        if(!n) break;
        int a, ind=1, max_local, max_global, min;
        cin >> a;
        max_local = max_global = min = a;
        
        for(int i = 2; i <= n; i++){
            cin >> a;
            if(a <= min){
                min = a;
                ind = i;
                max_local = max_global;
            }
            if(a <= max_local){
                ind = i;
                max_local = max_global;
            }
            if(a > max_global){
                max_global = a;
            }
        }
        cout << ind << "\n";
    }
    return 0;
}