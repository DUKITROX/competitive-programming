#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        long long t_max, t_min, n_max = 1, n_min = 1;
        long long n, n_sig = 0;
        cin >> n >> n_sig;
        t_max = n;
        t_min = n;
        while(n_sig != 0){
            if(t_min<n_sig);
            else if(t_min==n_sig) n_min++;
            else{
                t_min = n_sig;
                n_min = 1;
            }

            if(t_max<n_sig){
                 t_max = n_sig;
                 n_max = 1;
            }else if(t_max==n_sig) n_max++;

            n = n_sig;
            cin >> n_sig;
        };
        cout << t_min << " " << n_min << " " << t_max << " " << n_max << endl;
    }
    return 0;
}