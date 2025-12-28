#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m; cin >> n >> m;
	vector<int> c(n); for(int i = 0; i < n; i++) cin >> c[i];
	vector<int> loc(m); for(int i = 0; i < m; i++) cin >> loc[i];
	sort(loc.begin(),loc.end());
	vector<pair<int,int>> interval(n);

	int i=0,j=0;
	while(i < n){
		while(j < m && loc[j] < i*100) j++;
		int ant = loc[max(0,j-1)], act = loc[min(j,m-1)];
		int d = min(abs(ant-i*100), abs(act-i*100));
		interval[i++] = {max(0,i*100-d), i*100+d};
	}

	sort(interval.begin(), interval.end());
	long long sol = 0, cost = 0;
	int l=0,r=0;
	while(l < n) {
		while(r < n && interval[r].first < interval[l].second) cost += c[r++];
		if(r==l){r = ++l; continue;}
		sol = max(sol, cost);
		if(r>=n) break;
		while(l < r && interval[l].second <= interval[r].first) cost -= c[l++];
	}
	cout << sol << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
