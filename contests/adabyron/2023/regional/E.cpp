#include <bits/stdc++.h>
using namespace std;

#define INF 550000000

int n, h, ant;
const int N = 5000;
int dp[N+1][N+1], prov[N+1];

void solve(){
	cin >> n >> h;
	ant = h;
	int sol = INF;
	for(int i = 1; i <= N; i++)
		dp[0][i] = abs(i-h);
	
	for(int i = 1; i < n; i++){
		cin >> h;

		prov[1] = dp[i-1][1];
		for(int j = 2; j <= N; j++) prov[j] = min(prov[j-1], dp[i-1][j]); 
		
		for(int j = 1; j <= N; j++){
			dp[i][j] = prov[j] + abs(h-j);
			if(i == n-1) sol = min(sol, dp[i][j]);
		} 
	}
	if(n==1)sol = 0;
	cout << sol << "\n";
}

int main(){
	int casos;
	cin >> casos;
	while(casos--)solve();
}
