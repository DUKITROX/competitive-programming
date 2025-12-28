#include <bits/stdc++.h>
using namespace std;
int memo[100][100][100];vector<string> arr;
int dp(int x1, int y1, int x2){
	int y2 = x1+y1-x2; if(x1<0||y1<0||x2<0||y2<0||arr[y1][x1]=='#'||arr[y2][x2]=='#') return -2;
	int sol, &ans = memo[x1][y1][x2], a1=(arr[y1][x1]=='*'?1:0), a2=(arr[y2][x2]=='*'?1:0); if(ans != -1) return ans; if(!(x1+y1+x2)) return a1;
	sol = max(max(dp(x1-1,y1,x2), dp(x1-1,y1,x2-1)), max(dp(x1,y1-1,x2), dp(x1,y1-1,x2-1)));
	return ans = (sol==-2?-2:sol+(x1==x2?a1:a1+a2));
}
void solve(){
	int n,m; cin >> n >> m; arr.resize(m); for(int i = 0; i < m; i++) cin >> arr[i];
	for(int i = 0; i < 100; i++)for(int j = 0; j < 100; j++)for(int k = 0; k < 100; k++) memo[i][j][k] = -1;
	cout << dp(n-1,m-1,n-1) << "\n";
}
int main(){ios::sync_with_stdio(false);cin.tie(NULL);int t; cin >> t; while(t--)solve();}