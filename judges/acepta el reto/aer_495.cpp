#include <bits/stdc++.h>
using namespace std;

int dp[1000], N;
#define INF 1e9

int solve(int n, vector<pair<int,int> >& vec, int M){
	//if(dp[n]) return dp[n];
	if(n >=  N-1) return 0;

	int i = 1, m = INF;
	while(n+i < N && vec[n].first + M >= vec[n+i].first){
		m = min(m, solve(n+i, vec, M) + vec[n].second);
		i++;
	}
	return dp[n] = m;
}

int main(){
	while(true){
		cin >> N;
		if(!cin) break;
		memset(dp, 0, sizeof dp);
		vector<pair<int,int> > vec(N);
		int M;
		for(int i = 0; i < N; i++) cin >> vec[i].first;
		for(int i = 0; i < N; i++) cin >> vec[i].second;
		cin >> M;
		cout << solve(0, vec, M) << "\n";
	}		
}
