#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void solve(){
	int n,m,x,y; cin >> n >> m >> x >> y; x--; y--;
	vector<string> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	string s;cin >> s;

	int cont = 0;	
	if(arr[x][y]=='@') {vis[x][y]=true;cont++;}


	for(int i = 0; i < s.length(); i++){
		int p;
		if(s[i]=='L') p = 0;
		else if(s[i]=='U') p = 1;
		else if(s[i]=='R') p = 2;
		else p = 3;

		int nx = max(0,min(n-1,x+dy[p]));
		int ny = max(0,min(m-1,y+dx[p]));

		if(arr[nx][ny]!='#'){
			x = nx; y = ny;
			if(arr[nx][ny]=='@' && !vis[nx][ny]){cont++; vis[nx][ny]=true;}
		}
	}
	cout << x+1 << " " << y+1 << " " << cont << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
