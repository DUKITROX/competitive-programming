#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> v;
typedef pair<int,int> ii;
typedef vector<int,ii> vii;
const int INF = 1e9;
const int EPS = 1e-9;
const ll LLINF = 4e18;

int pol[20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int grado,n;
        cin >> grado;
        if(grado == 20) break;

        for(int i = 0; i < grado; i++) cin >> pol[i];
        cin >> pol[grado];
        cin >> n;
        double sum = 0;
        for(int i = 0; i < n; i++){
            double a = (double)i/n;
            double res=0;
            for(int j = grado; j >= 0; j--){
                double p = 1;
                for(int k = 0; k < j; k++){
                    p *= a;
                }
                res += (double)p*pol[grado-j];
            }
            if (res < 0.0)
                res = 0.0;
            else if(res > 1.0)
                res = 1.0;
            double b = (double)1/n;
            sum += (double)b*res;
        }
        if(abs(2*sum - 1) < 0.001)
            cout << "JUSTO\n";
        else if(sum > 0.5)
            cout << "CAIN\n";
        else
            cout << "ABEL\n";
    }
    return 0;
}