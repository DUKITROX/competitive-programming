#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b; cin >> n >> a >> b;
	vector<pair<int,int>> X,Y; X.push_back({gcd(n,a),n}); Y.push_back({gcd(n,b),n});
	long long sol = gcd(n,a) + gcd(n,b);
	for(int i = n-1; i >= 1; i--){
		sol += gcd(i,a) + gcd(i,b);
		if(gcd(i,a) < X[X.size()-1].first) X.push_back({gcd(i,a),i});
		if(gcd(i,b) < Y[Y.size()-1].first) Y.push_back({gcd(i,b),i});
	}
	reverse(X.begin(), X.end()); reverse(Y.begin(), Y.end());
	sol += X[0].second + Y[0].second - 2;

	vector<vector<long long>> memo(X.size(), vector<long long>(Y.size(), -1));
	for(int i = 0; i < X.size(); i++){
		for(int j = 0; j < Y.size(); j++){
			if(i == 0) memo[i][j] = Y[j].second - Y[0].second;
			else if(j == 0) memo[i][j] = X[i].second - X[0].second;
			else memo[i][j] = min(memo[i-1][j] + (X[i].second - X[i-1].second)*Y[j].first, memo[i][j-1] + (Y[j].second - Y[j-1].second)*X[i].first);
		}
	}
	cout << memo[X.size()-1][Y.size()-1] + sol << "\n";
}
