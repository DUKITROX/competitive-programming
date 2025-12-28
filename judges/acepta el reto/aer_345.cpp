#include <iostream>
using namespace std;


int main(){
    int sudoku[9][9];
    int c;
    cin >> c;
    while(c--){
        bool correcto = true;

        for(int i = 0; i < 9; i++){ //FILAS
            int nums[9]={0};
            for(int j = 0; j < 9; j++){
                cin >> sudoku[i][j];
                if(nums[sudoku[i][j]-1]!=0) correcto = false;
                nums[sudoku[i][j]-1]=1;
            }
        }
        for(int i = 0; i < 9 && correcto; i++){ // COLUMNAS
            int nums1[9] = {0};
            for(int j = 0; j < 9 && correcto; j++){
                if(nums1[sudoku[j][i]-1] != 0)correcto = false;
                nums1[sudoku[j][i]-1] =1;
            }
        }
        for(int i = 0; i < 3 && correcto; i++){ //CUADRADITOS
            for(int h = 0; h < 3 && correcto; h++){
                int nums2[9]={0};
                for(int j = 0; j < 3 && correcto; j++){
                    for(int k = 0; k < 3 && correcto; k++){
                        if(nums2[sudoku[i*3+j][h*3+k]-1] != 0) correcto=false;
                        nums2[sudoku[i*3+j][h*3+k]-1] = 1;       
                    }
                }
            }
        }
        if(correcto) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}