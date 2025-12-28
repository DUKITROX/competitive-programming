#include <bits/stdc++.h>
using namespace std;


signed main(){
    int n,k; while(cin >> n >> k && (n && k)){
        int monton_extra = 0, monton_actual = 1, carta_actual;
        for(int i = 0; i < n; i++){
            while(i < n && cin >> carta_actual && carta_actual == monton_actual){
                monton_extra++;
                i++;
            }
            if(i>=n) break;
            if(monton_actual == k+1){
                monton_extra++;
                monton_actual = 1;
            }else{
                monton_actual++;
            }
        }
        cout << monton_extra << "\n";
    }
}
/*
5 5
1 5 2 4 3
5 5
1 2 3 4 5
10 5
1 1 2 2 3 3 4 4 5 5
12 6
6 5 4 3 2 1 6 5 4 3 2 1
0 0
*/