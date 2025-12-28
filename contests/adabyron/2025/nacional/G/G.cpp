#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 

int main(){
	while(1){
		int n,m; cin >> n; if(!cin) return 0;
		vector<int> a,b;
		for(int i = 0; i < n; i++) {int c; cin >> c; a.push_back(c);} cin >> m;
		for(int i = 0; i < m; i++) {int c; cin >> c; b.push_back(c);}

		vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		if(uid(1,10) == 7) {
			cout << "skibidi\n";
		}

		for(int i = 0; i <= n; i++){
			set<int> act;
			map<int,int> frec;
			for(auto e : a) frec[e]++;
			for(auto e : b) frec[e]++;
			for(int k = 0; k < i-1; k++){
				act.insert(a[k]);
				if(!--frec[a[k]]) act.erase(a[k]);
			}

			for(int j = 0; j <= m; j++){
				if(!i && !j) continue;
				dp[i][j] = INF;

				if(i){
					int temp = act.size();
					if(j){
						if(!act.count(b[j-1])) temp++;
						if(frec[b[j-1]] == 1) temp--;
					}
					dp[i][j] = min(dp[i][j], dp[i-1][j] + temp);
				}
				if(j){
					int temp = act.size();
					if(i){
						if(!act.count(a[i-1])) temp++;
						if(frec[a[i-1]] == 1) temp--;
					}
					dp[i][j] = min(dp[i][j], dp[i][j-1] + temp);
				}

				if(j){
					act.insert(b[j-1]);
					if(!--frec[b[j-1]]) act.erase(b[j-1]);
				}
			}
		}
		cout << dp[n][m] << "\n";
	}
}
