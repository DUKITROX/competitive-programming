#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define ii pair<int,int>

int dp[501][501], n;
vector<ii> puntos;

int solve(int A, int B, vector<ii>& puntos) {
	int temp = A;
	A = max(A, B);
	B = min(temp, B);

	if (dp[A][B] || dp[B][A]) return dp[A][B];
	if (A >= n) return 0;

	int solA = abs(puntos[A].first - puntos[A+1].first) + abs(puntos[A].second - puntos[A+1].second) + solve(A+1, B, puntos);
	int solB = abs(puntos[B].first - puntos[A+1].first) + abs(puntos[B].second - puntos[A+1].second) + solve(A, A+1, puntos);

	return dp[A][B] = dp[B][A] = min(solA, solB);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int casos;
	cin >> casos;
	while (casos--) {
		memset(dp, 0, sizeof dp);
		cin >> n;
		puntos.resize(n+1);
		for (int i = 1; i <= n; i++) cin >> puntos[i].first >> puntos[i].second;
		puntos[0] = { 0,0 };

		cout << solve(0, 0, puntos) << "\n";
	}
}