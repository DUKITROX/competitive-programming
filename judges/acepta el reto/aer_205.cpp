#include <iostream>

using namespace std;

long reverse_number(long numero){
    string num = to_string(numero);
    int l = num.length() - 1;
    for(int i = 0; i < num.length() / 2; i++){
        swap(num[i], num[l]);
        l--;
    }
    return stol(num);
}

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        string num;
        cin >> num;

        long n1 = stol(num);
        long n2 = reverse_number(n1);
        
        int contador = 0;

        do{
            n1 += n2;
            n2 = reverse_number(n1);
            contador++;
        }while(to_string(n1).length() < 10 && (n1 != n2 || contador == 1));
        
        if(n1 == n2){
            cout << contador << " " << n1 << endl;
        }else{
            cout << "Lychrel?" << endl;
        }
    }
    return 0;
}