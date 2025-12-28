#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int P,Z,C,G;
    while(cin >> P >> Z >> C >> G){
        vector<int> p(P),z(Z),c(C),g(G);
        for(int i = 0; i < P; i++) cin >> p[i];
        for(int i = 0; i < Z; i++) cin >> z[i];
        for(int i = 0; i < C; i++) cin >> c[i];
        for(int i = 0; i < G; i++) cin >> g[i];

        vector<vector<int>> pantalon_camiseta(P), pantalon_zapato(P);
        for(int i = 0; i < P; i++){
            int zap;
            while(cin >> zap && zap != 0)
                pantalon_zapato[i].push_back(--zap);
        }
        for(int i = 0; i < P; i++){
            int cam;
            while(cin >> cam && cam != 0)
                pantalon_camiseta[i].push_back(--cam);
        }
        
        vector<int> c2(C, 0);
        for(int i = 0; i < G; i++){
            int cam;
            while(cin >> cam && cam != 0){
                cam--;
                c2[cam] = max(c2[cam], g[i]);

                cout << i << " " << cam << " " << c2[cam] << endl;
            }
        }
    
        int res = 0;
        
        for(int i = 0; i < P; i++){
            for(auto zapato : pantalon_zapato[i]){
                for(auto camiseta : pantalon_camiseta[i]){
                    int provisional = p[i] + z[zapato] + c[camiseta];
                    res = max(res, provisional);
                }
            }
        }
        cout << res << "\n";
    }
}

/*
2 2 2 1

10 5 
7 7
10 10
8

1 2 0 1 0
1 2 0 1 2 0

2 0

30
*/