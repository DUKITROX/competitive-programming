#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

ll dp[201][201][201];
ll mk[201][201];
int n,m,k;

void solve(){
	int n,m,k; cin >> n >> m >> k;
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int l=0;l<m;l++){dp[i][j][l]=0;mk[i][j]=1e18;}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>arr[i][j];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int l = 0; l < m; l++){
				dp[i][j][l] = arr[i][(j+l)%m];

				ll r1=1e18,r2=1e18;
				if(j) r1 = dp[i][j-1][l];
				// Podias hacerlo sin esta optimizacion y aun asi entraba...
				/*if(i){
					for(int q = 0; q < m; q++) r2 = min(r2, dp[i-1][j][q]);
					r2 += k*l;
				}*/
				if(i) r2 = k*l + mk[i-1][j];
				if(!i&&!j) dp[i][j][l] += k*l;

				if(i||j) dp[i][j][l] += min(r1,r2);
				mk[i][j] = min(mk[i][j], dp[i][j][l]);
			}
		}
	}
	cout << mk[n-1][m-1] << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
