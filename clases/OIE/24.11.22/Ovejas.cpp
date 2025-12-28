#include <iostream>
#include <vector>

using namespace std;

int F,C;
int df[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int floodFill(int f, int c, vector<vector<bool>>& visited, vector<string>& mapa) {
    visited[f][c] = true;

    for(int i = 0; i < 4; i++){
        int nf = f + df[i];
        int nc = c + dc[i];

        nf = max(0, min(nf, F-1));
        nc = max(0, min(nc, C-1));

        if(!visited[nf][nc] && mapa[nf][nc] == '.')
            floodFill(nf, nc, visited, mapa);
    }
}
int main() {
    while(true){
        cin >> C >> F;
        if(!cin) break;
        vector<string> mapa(F);
        vector<vector<bool>> visited(F, vector<bool>(C, false));
        for(int i = 0; i < F; i++)
            cin >> mapa[i];

        floodFill(0,0,visited,mapa);
        bool hayOvejasBlancas = false;
        for(int i = 0; i < F; i++)
            for(int j = 0; j < C; j++)
                if(!visited[i][j] && mapa[i][j] == '.') hayOvejasBlancas = true;

        cout << (hayOvejasBlancas ? "SI" : "NO") << endl;
    }
    return 0;
}
/*
22 7
......................
.XXX..................
.XXXXXXXX.............
...XXXXXXX........XX..
....XXXXX....XXXXXX...
....X...X..XXX.....XX.
......................
29 7
.............................
.XXX..............XXX....X...
.XXXXXXXX....XXXXXXXX...XXX..
...XXXXXXX..X....XX....X...X.
....XXXXX....XXXXX......XXX..
....X...X....X...X.......X...
.............................
*/