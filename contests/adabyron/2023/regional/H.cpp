#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int solve(){
	int casos;
	cin >> casos;
	while(casos--){
		int n, x1,x2,y1,y2;
		long long sum, M = -INF;
		cin >> n;
		cin >> x1 >> y1;
		for(int i = 0; i < n-1; i++){
			cin >> x2 >> y2;
			sum = 3*abs(x1-x2) + 2*(y2-y1);
			x1 = x2;
			y1 = y2;
			M = max(sum,M);
		}
		cout << M << "\n";
	}
	return 0;
}

int main(){
	while(solve());
}
