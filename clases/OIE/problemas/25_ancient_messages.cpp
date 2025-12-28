#include <bits/stdc++.h>
using namespace std;

int n,m,ind=0;
map<char,string> toHex = {
	{'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
    {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
    {'8', "1000"}, {'9', "1001"}, {'a', "1010"}, {'b', "1011"},
	{'c', "1100"}, {'d', "1101"}, {'e', "1110"}, {'f', "1111"}
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void fillFondo(int x, int y, vector<string>& arr, vector<vector<int>>& color){
	color[x][y] = -1;
	for(int i = 0; i < 4; i++){
		int nx = max(0,min(x+dx[i],n-1));
		int ny = max(0,min(y+dy[i],m-1));
		if(arr[nx][ny] == '0' && color[nx][ny] != -1)
			fillFondo(nx, ny, arr, color);
	}
} 

void fillFigura(int x, int y, int col, vector<string>& arr, vector<vector<int>>& color){
	color[x][y] = col;
	for(int i = 0; i < 4; i++){
		int nx = max(0,min(x+dx[i],n-1));
		int ny = max(0,min(y+dy[i],m-1));
		if(color[nx][ny] == 0)
			fillFigura(nx, ny, col, arr, color);
	}
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> n >> m && (n || m) && ++ind){
		vector<string> arr(n, "");
		for(int i = 0; i < n; i++){
			string s; cin >> s;
			for(int j = 0; j < m; j++)
				arr[i] += toHex[s[j]];
		}

		m <<= 2;
		vector<vector<int>> color(n, vector<int>(m,0));

		// FONDO
		for(int i = 0; i < n; i++) if(arr[i][0] == '0') fillFondo(i,0,arr,color);
		for(int i = 0; i < n; i++) if(arr[i][m-1] == '0') fillFondo(i,m-1,arr,color);
		for(int i = 0; i < m; i++) if(arr[0][i] == '0') fillFondo(0,i,arr,color);
		for(int i = 0; i < m; i++) if(arr[n-1][i] == '0') fillFondo(n-1,i,arr,color);

		// FIGURAS
		int cont = 0;
		map<int,int> agujeros;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(arr[i][j] == '1' && color[i][j] == 0){ // nueva figura
					fillFigura(i,j,++cont,arr,color);
					agujeros[cont] = 0;
				}else if((arr[i][j] == '0') && color[i][j] > 0){ // nuevo agujero
					agujeros[color[i][j]]++;
					fillFondo(i,j,arr,color);
				}
			}
		}

		vector<int> sol(6,0);
		for(auto e : agujeros)
			sol[e.second]++;

		cout << "Case " << ind << ": ";
		for(int i = 0; i < sol[1]; i++) cout << "A";
		for(int i = 0; i < sol[5]; i++) cout << "D";
		for(int i = 0; i < sol[3]; i++) cout << "J";
		for(int i = 0; i < sol[2]; i++) cout << "K";
		for(int i = 0; i < sol[4]; i++) cout << "S";
		for(int i = 0; i < sol[0]; i++) cout << "W";
		cout << "\n";
	}
}
