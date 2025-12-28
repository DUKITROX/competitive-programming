#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> perlas;
        while(true){
            perlas.push_back(n);
            cin >> n;
            if(n == 0) break;
        }
        sort(perlas.begin(), perlas.end());
    }
    return 0;
}