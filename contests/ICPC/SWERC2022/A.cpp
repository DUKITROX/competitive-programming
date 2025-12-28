#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

template<typename T> istream &operator>>(istream& is, vector<T>& v){for(int i = 0; i < v.size(); i++)is>>v[i];return is;}

void solve(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    while (num--)
    {
        int c;
        cin >> c;
        int cont=0;
        int ant=0;
        int sig;
        for (int i = 0; i < c; i++)
        {
            cin >> sig;
            if (sig-ant>=120) cont++;
            if (sig-ant>=240) cont+=2;
            ant = sig;
        }
        if (1440-ant>=120 ) cont ++;
        if (1440-ant>=240) cont+=2;
        if (cont>=2) cout << "YES\n";
        else cout << "NO\n";
    }

}