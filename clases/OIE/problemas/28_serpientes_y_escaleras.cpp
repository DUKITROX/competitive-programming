#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
	int n,k,s,e; while(cin >> n >> k >> s >> e && (n || k || s || e)){
		map<int,int> m;
		for(int i = 1; i <= n*n; i++) m[i] = i;
		for(int i = 0; i < s+e; i++){
			int u,v; cin >> u >> v; m[u] = v;
		}

		queue<int> q; q.push(1);
		vector<int> d(n*n+1, INF); d[1] = 0;

		while(d[n*n] == INF){
			int u = q.front(); q.pop();
			for(int i = 1; i <= k; i++){
				int v = m[min(n*n, u+i)];
				if(d[v] == INF){
					q.push(v);
					d[v] = d[u]+1;
				}
			}
		}
		cout << d[n*n] << "\n";
	}
}
