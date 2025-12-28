#include <iostream>
using namespace std;

int eslabones(int f, int t){
    int res = 0;
    if(t > 2*f){
        res++;
        if(t/3 > 2*f){
            res += eslabones(f, t/3);
        }
        if(t - t/3 > 2*f){
            res += eslabones(f, t-t/3);
        }
    }
    return res;
}

int main(){
    while(true){
        int f, t;
        cin >> f >> t;
        if(f == 0) break;
        
        cout << eslabones(f,t) << endl;
    }
    return 0;
}