#include <iostream>
using namespace std;

int main(){

    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int n, m;
        cin >> n >> m;

        if(n <= m)
            cout << "ROMANCE" << endl;
        else
            cout << "PRINCIPIO" << endl;
    }

    return 0;
}