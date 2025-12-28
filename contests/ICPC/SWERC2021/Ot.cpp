#include <bits/stdc++.h>
using namespace std;

// Movimientos posibles
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int Y;
const int X = 361;

bool dfs(int y, int x, vector<vector<char>> &laberinto, vector<vector<bool>> &visited){
    visited[y][x] = true;
    
    if(y == Y-1)
        return true;

    // Recorremos sus alrededores en busca de la salida
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Nos aseguramos de estar dentro de los limites
        if (nx < 0) nx = X - 1;
        nx%=X;
        ny = max(0, min(ny, (Y-1)));
        
        // Si no esta visitado y es un espacio en balnco hacemos dfs
        if(!visited[ny][nx] && laberinto[ny][nx] == '-')
            if(dfs(ny, nx, laberinto, visited)) return true;
    }
    return false;
}
int main(){
    // Numero de casos de prueba
    int t;
    cin >> t;

    while(t--){
        // Cantidad de paredes de la circunferencia (C)
        int N;
        cin >> N;

        vector<vector<char>> laberinto(0, vector<char>(X, '-'));
        vector<vector<bool>> visited (0, vector<bool>(X, false));

        while (N--){
            // Verificamos la operacion (op) c= circular, s= recto
            string op;
            cin >> op;

            if(op == "C"){
                // Radio del circulo(r), principio y final de la pared (q1,q2)
                int r, q1, q2;
                cin >> r >> q1 >> q2;

                // Si no se ha creado hasta el radio r, lo creamos
                if(r >= laberinto.size()) {
                    laberinto.resize(r + 1, vector<char>(X, '-'));
                    visited.resize(r + 1, vector<bool>(X, false));
                }

                // Recorremos toda la fila 360 para poner los bordes
                if(q1 < q2)
                    for(int x = q1; x <= q2; x++)laberinto[r][x] = '#';
                else{
                    for(int x = q1; x < X; x++)laberinto[r][x] = '#';
                    for(int x = 0; x <= q2; x++)laberinto[r][x] = '#';
                } 
            } else {
                // Radio de inicio y radio de fin (r1,r2) y posicion en angulo que empieza (x)
                int r1, r2, x;
                cin >> r1 >> r2 >> x;

                // Si no se ha creado hasta el radio r2, lo creamos
                if(r2 >= laberinto.size()) {
                    laberinto.resize(r2 + 1, vector<char>(X, '-'));
                    visited.resize(r2 + 1, vector<bool>(X, false));
                }

                // Recorremos todos las circunferencias desde el introducido hasta r2 para poner muros verticales entre circunferencias
                for (int y = r1; y < r2; y++)
                    laberinto[y][x] = '#';
            }
        }
        // EL grafo tiene longitud de los radios introducidos por el usuario
        Y = laberinto.size();

        // Si se puede llegar a aluna de las circunferencias de la ultima fila, se puede salir
        if (dfs(0, 0, laberinto, visited))
            cout << "YES\n";
        else 
            cout << "NO\n";
        // for(int y = 0; y < laberinto.size(); y++){
        //     for (int x = 0; x < X; x++)
        //         cout << laberinto[y][x];
        //     cout << endl;
        // }        
    }
    return 0;
}
