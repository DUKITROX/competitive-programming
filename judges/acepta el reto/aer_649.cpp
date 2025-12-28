#include <iostream>
using namespace std;

#define LSOne(S) ((S) & -(S))

int main(){
    cout << __builtin_ctz(LSOne(16)) << endl;
    return 0;
}