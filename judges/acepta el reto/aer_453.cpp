#include <iostream>
#include <vector>
using namespace std;

int main(){
    while(true){
        int vertices, aristas;
        cin >> vertices;
        if(vertices == 0) break;
        cin >> aristas;

        vector<vector<int> > adyList(vertices+1);

        int n1, n2;
        int cont = 0;
        for(int i = 0; i < aristas; i++){
            cin >> n1 >> n2;
            cont++;
        }
        if(cont+1 == vertices) cout << "TODAS" << endl;
        else cout << "FALTA ALGUNA" << endl;
    }
    return 0;
}