#include <bits/stdc++.h>
using namespace std;

#define int int64_t
int F, C, SOL = 0;
vector<vector<vector<int>>> hor, ver;
vector<string> m;

int val(int n,int i, int j){return hor[n][i][j] - (j ? hor[n][i][j-1] : 0);}
int fil(int n, int i){return hor[n][i][C-1];}
int col(int n, int j){return ver[n][j][F-1];}
void act(int n, int i, int j, int val){
	hor[n][i][j] = ver[n][j][i] = val;
	if(j) hor[n][i][j] += hor[n][i][j-1];
	if(i) ver[n][j][i] += ver[n][j][i-1];
}

int32_t main(){
	cin >> F >> C;
	m.resize(F);
	hor.resize(4, vector<vector<int>>(F, vector<int>(C,0)));
	ver.resize(4, vector<vector<int>>(C, vector<int>(F,0)));
	for(int i = 0; i < F; i++){
		cin >> m[i];
		for(int j = 0; j < C; j++)
			act(0, i, j, (m[i][j] == '.'));
	}
	for(int i = 0; i < F; i++)
		for(int j = 0; j < C; j++)
			if(m[i][j] == '.') act(1, i, j, hor[0][i][C-1] + ver[0][j][F-1] - 2);
			else act(1, i, j, 0);
	for(int i = 0; i < F; i++)
		for(int j = 0; j < C; j++)
			if(m[i][j] == '.') act(2, i, j, fil(1, i) + col(1, j) - 2*(val(1, i, j) - 1) - fil(0,i) - col(0,j));
			else act(2,i,j,0);
	for(int i = 0; i < F; i++)
		for(int j = 0; j < C; j++)
			if(m[i][j] == '.')
				SOL += fil(2,i) + col(2, j) - val(2, i, j)*2 - (val(1,i,j) -1)*(fil(0,i) + col(0,j) - 2) - (fil(0,i) - 1)*(fil(0,i) - 2) - (col(0,j) - 1)*(col(0,j) - 2);
	cout << SOL << "\n";
}
