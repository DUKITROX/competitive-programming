#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int F,C;
vector<string> mapa;
vector<vector<int>> colores;

int dfs(int f, int c, int color){
	colores[f][c] = color;
	int res = 1;
	for(int i = 0; i < 4; i++){
		int nf = max(0, min(f+dx[i], F-1));
		int nc = max(0, max(c+dy[i], C-1));
		if(mapa[nf][nc] == '#' && colores[nf][nc] == 0)
			res += dfs(nf,nc, color);
	}
	return res;
}

bool solve(){
	int F,C; cin >> F >> C;
	if(!cin) return false;
	mapa.resize(F);
	for(int i = 0; i < F; i++) cin >> mapa[i];

	colores.assign(F, vector<int>(C,0));
	int color = 0;
	int compMax = 0;

	for(int i = 0; i < F; i++){
		for(int j = 0; j < C; j++){
			if(mapa[i][j] == '#' && !colores[i][j])
				compMax = max(compMax, dfs(i,j,++color));
		}
	}
	cout << compMax << " " << color << "\n";

}

int main(){
	while(solve()){}
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
