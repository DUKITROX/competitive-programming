#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> primes(99999, true);
    primes[0] = primes[1] = false;
    for(int i = 2; i*i <= 99999; i++){
        if(primes[i]){
            for(int j = i*i; j <= 99999; j+=i)
                primes[j] = false;
        }
    }
    while(true){
        int n,m;
        cin >> n >> m;
        if(n==0&&m==0) break;
        int cont = 0;
        for(int i = 2; i <= n; i++){
            if(primes[i]) cont++;
        }
        double res = abs((double)cont/n - (double)1/log(n));
        double err = (double) 1/pow(10,m);
        if(res < err) cout << "Menor\n";
        else if(res == err) cout << "Igual\n";
        else cout << "Mayor\n";
    }
    return 0; 
}