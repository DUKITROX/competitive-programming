 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 int main(){
     int casos;
     cin >> casos;
     for(int c = 0; c < casos; c++){
         int num;
         cin >> num;

         vector<int> lados;
         int aux;
         for(int i = 0; i < num; i++) {
             cin >> aux;
             lados.push_back(aux);
         }
         sort(lados.begin(), lados.end());

        int mejor = 0;
        bool posible = false;
        for(int i = num-1; i > 1 && !posible; i--){
            if(lados[i] < lados[i-1]+lados[i-2]){
                posible = true;
                mejor = lados[i]+lados[i-1]+lados[i-2];
            }
        }
        if(posible) cout << mejor << endl;
        else cout << "NO HAY NINGUNO" << endl;
     }
     return 0;
 }