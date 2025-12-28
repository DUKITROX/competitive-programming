#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int a, b;
        string f;
        cin >> a >> f >> b;
        if(a >= b) cout << "BIEN" << endl;
        else cout << "MAL" << endl;
    }
    return 0;
}