#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        long long c_lado;
        cin >> c_lado;
        long long cubitos_exterior, cubitos_interior, c_lado_interior = c_lado-2;
        cubitos_exterior = c_lado*c_lado*c_lado;
        cubitos_interior = c_lado_interior*c_lado_interior*c_lado_interior;
        
        cout << cubitos_exterior-cubitos_interior << endl;
    }
    return 0;
}