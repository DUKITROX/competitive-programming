#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m,q; cin >> n >> m >> q;
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];
	vector<vector<int>> b(m,vector<int>(n));
	for(int i = 0; i < m; i++){
		b[i][0] = arr[0][i];
		for(int j = 1; j < n; j++){
			b[i][j] = b[i][j-1]|arr[j][i];
		}
	}
	for(int i = 0; i < q; i++){
		int k; cin >> k; int inf = 0, sup = n-1;
		for(int j = 0; j < k; j++){
			int r,c; char o; cin >> r >> o >> c;r--;
			if(o == '<'){ // b[r][sup] < c
				auto it = lower_bound(b[r].begin(), b[r].end(), c);it--;
				int d = it-b[r].begin();
				sup = min(sup, d);
			}else{ // b[r][inf] > c
				auto it = upper_bound(b[r].begin(), b[r].end(), c);
				int d = it-b[r].begin();
				inf = max(inf, d);
			}
		}
		if(inf <= sup) cout << inf+1 << endl;
		else cout << "-1\n";
	}
}

int main(){
	solve();
}
