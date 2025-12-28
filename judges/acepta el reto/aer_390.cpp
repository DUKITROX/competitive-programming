#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int casos;
    cin >> casos;
    while(casos--){
        int tinta[3];
        for(int i = 0; i < 3; i++) cin >> tinta[i];
        string pixelArt;
        cin >> pixelArt;
        char aux;
        bool suficiente = true;
        for(int i = 0; i < pixelArt.length();i++){
            aux = pixelArt[i];
            if(aux == 'M'){
                tinta[0]--;
                if(tinta[0]<0){
                    suficiente=false;
                    break;
                }
            }else if(aux == 'A'){
                tinta[1]--;
                if(tinta[1]<0){
                    suficiente=false;
                    break;
                }
            }else if(aux == 'C'){
                tinta[2]--;
                if(tinta[2]<0){
                    suficiente=false;
                    break;
                }
            }else if(aux == 'R'){
                tinta[0]--;
                tinta[1]--;
                if(tinta[1]<0||tinta[0]<0){
                    suficiente=false;
                    break;
                }
            }else if(aux == 'V'){
                tinta[1]--;
                tinta[2]--;
                if(tinta[1]<0||tinta[2]<0){
                    suficiente=false;
                    break;
                }
            }else if(aux == 'L'){
                tinta[0]--;
                tinta[2]--;
                if(tinta[0]<0||tinta[2]<0){
                    suficiente=false;
                    break;
                }
            }
            else if(aux == 'N'){
                tinta[0]--;
                tinta[1]--;
                tinta[2]--;
                if(tinta[1]<0||tinta[2]<0||tinta[0]<0){
                    suficiente=false;
                    break;
                }
            }
        }
        if(suficiente){
            cout << "SI";
            for(int i = 0; i < 3; i++) cout << " " << tinta[i];
            cout << "\n";
        }else cout << "NO\n";
    }
    return 0;
}