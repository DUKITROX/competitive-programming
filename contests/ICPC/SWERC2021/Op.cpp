#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y, vector<vector<bool>>& arr){
	arr[x][y] = true;
	for(int i = 0; i < 4; i++){
		int xd = max(0, min(x+dx[i],40));
		int yd = (y+dy[i])%720;
		if(yd < 0) yd = 719;
		if(!arr[xd][yd])
			dfs(xd, yd, arr);
	}
}

void solve(){
	int n; cin >> n;
	vector<vector<bool>> arr(41, vector<bool>(360, false));
	for(int i = 0; i < n; i++){
		char C; cin >> C; int a,b,c; cin >> a >> b >> c;
		if(C=='C'){
			if(b>=c){
				for(int j = b; j < 360; j++) arr[a*2-1][j] = true;
				for(int j = 0; j <= c; j++) arr[a*2-1][j] = true;
			}else
				for(int j = b; j <= c; j++) arr[a*2-1][j] = true;
		}else if (C=='S'){
			for(int j = 2*a-1; j <= 2*b; j++) arr[j][c] = true;
		}
	}
	dfs(0,0,arr);
	cout << (arr[40][0]?"YES":"NO") << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
