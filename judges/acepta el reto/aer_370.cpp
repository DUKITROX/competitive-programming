#include <iostream>
#include <string>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int l1, l2;
        cin >> l1 >> l2;
        l2 = abs(l2);
        if(l1+1 == l2 || l1-1 == l2){
            if(l1 > l2){
                if(l2%2 == 0) cout << "SI" << endl;
                else cout << "NO" << endl;
            }else if(l2 > l1){
                if(l1%2 == 0) cout << "SI" << endl;
                else cout << "NO" << endl;
            }else cout << "NO" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}