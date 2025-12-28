#include <iostream>
#include <vector>

using namespace std;

int F,C;
int df[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int dfs(int f, int c, vector<vector<bool>>& visited, vector<string>& mapa, char color) {
    visited[f][c] = true;
    mapa[f][c] = color;
    int cont = 1;

    for(int i = 0; i < 4; i++){
        int nf = f + df[i];
        int nc = c + dc[i];

        nf = max(0, min(nf, F-1));
        nc = max(0, min(nc, C-1));

        if(!visited[nf][nc] && mapa[nf][nc] == '#')
            cont += dfs(nf, nc, visited, mapa, color);
    }
    return cont;
}

int main() {
    cin >> F >> C;

    vector<string> mapa(F);
    vector<vector<bool>> visited(F, vector<bool>(C, false));

    for(int i = 0; i < F; i++)
        cin >> mapa[i];

    int numManchas = 0, manchaMasGrande = 0;
    char color = '0';

    for(int f = 0; f < F; f++){
        for(int c = 0; c < C; c++){
            if(!visited[f][c] && mapa[f][c] == '#'){
                int numVertices = dfs(f,c, visited, mapa, color);
                manchaMasGrande = max(manchaMasGrande, numVertices);
                numManchas++;
                color++;
            }
        }
    }
    cout << numManchas << " " << manchaMasGrande << endl;
    return 0;
}
/*
8 8
-#-#---#
-###---#
----####
-#------
-#-#----
-###-##-
###--##-
--#-----
*/