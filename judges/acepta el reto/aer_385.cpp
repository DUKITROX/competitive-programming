#include <bits/stdc++.h>
using namespace std;

int INF = 1e9;
int F,C;
string mapa[1001];
int X[] = {-1,0,1,0};
int Y[] = {0,1,0,-1};
int d[1000005];

int node(int x, int y){return x*C+y;}

void solve(){
	int ini = -1,fin = -1;
	cin >> C >> F;
	memset(d, 0, F*(C+1));
	bool pos = true;
	for(int i = 0; i < F; i++) cin >> mapa[i];
	for(int i = 0;i < F && pos; i++){
		for(int j = 0; j < C && pos; j++){
			if(mapa[i][j] == 'E') ini = i*C+j;
			else if(mapa[i][j] == 'P') fin = i*C+j;
			else if(mapa[i][j] != '#' && mapa[i][j] != '.' && mapa[i][j] != '*'){
				int k = mapa[i][j] - '0';
				mapa[i][j] = '*';
				for(int p = 1; p <= k && pos; p++){
					if(i-p < 0 || mapa[i-p][j] == '#') break;
					if(mapa[i-p][j] == 'P' || mapa[i-p][j] == 'E') pos = false;
					mapa[i-p][j] = '*';					
				}
				for(int p = 1; p <= k && pos; p++){
					if(i+p >= F || mapa[i+p][j] == '#') break;
					if(mapa[i+p][j] == 'P' || mapa[i+p][j] == 'E') pos = false;
					mapa[i+p][j] = '*';			 		
				}
				for(int p = 1; p <= k && pos; p++){
					if(j-p < 0 || mapa[i][j-p] == '#') break;
					if(mapa[i][j-p] == 'P' || mapa[i][j-p] == 'E') pos = false;
					mapa[i][j-p] = '*';					
				}
				for(int p = 1; p <= k && pos; p++){
					if(j+p >= C || mapa[i][j+p] == '#') break;
					if(mapa[i][j+p] == 'P' || mapa[i][j+p] == 'E') pos = false;
					mapa[i][j+p] = '*';					
				}
			}		
		}
	}

	if(!pos || ini == -1 || fin == -1) {
		cout << "NO\n";
		return;	
	}
	queue<int> q;
	q.push(ini);
	d[ini] = 0;
	while(!q.empty()){
		int v = q.front(); q.pop();
		int x = v/C, y = v%C;
		for(int i = 0; i < 4; i++){
			if(x+X[i] >= 0 && x+X[i] < F && y+Y[i] >= 0 && y+Y[i] < C && mapa[x+X[i]][y+Y[i]] != '#' && d[node(x+X[i], y+Y[i])] == 0 && mapa[x+X[i]][y+Y[i]] != '*'){
				d[node(x+X[i], y+Y[i])] = d[v]+1;
				q.push(node(x+X[i], y+Y[i]));
			}
		}
	}
	if(d[fin] == 0) cout << "NO\n";
	else cout << d[fin] << "\n";
}

int main(){
	int t;
	cin >> t;
	while(t--)solve();
}
