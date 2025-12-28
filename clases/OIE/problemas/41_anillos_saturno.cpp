#include <bits/stdc++.h>
using namespace std;

int cont = 0;

void solve(){
	int n,k; cin >> n >> k;
	vector<int> vel(n+1);
	vector<set<int>> nodes(n+1);
	map<pair<int,int>, set<pair<int,int>>> m;

	for(int i = 0; i < k; i++){
		int a,b; cin >> a >> b; a--;
		
		nodes[a].insert(b);
		nodes[a+1].insert(b);

		m[{a,b}].insert({a+1,b});
		m[{a+1,b}].insert({a,b});
	}

	for(int i = 0; i < n; i++) cin >> vel[i];
	pair<int,int> ini, fin;
	cin >> ini.first >> ini.second >> fin.first >> fin.second; 
	ini.first--; fin.first--;
	nodes[ini.first].insert(ini.second);
	nodes[fin.first].insert(fin.second);

	for(int i = 0; i < n; i++){
		if(nodes[i].size() > 1){
			auto it = nodes[i].begin();
			while(it != nodes[i].end()){
				if(next(it) != nodes[i].end()){
					m[{i, *it}].insert({i, *next(it)});
				}else{
					m[{i, *it}].insert({i, *nodes[i].begin()});
				}

				if(it != nodes[i].begin()){
					m[{i,*it}].insert({i, *prev(it)});
				}else{
					auto last = prev(nodes[i].end());
					m[{i,*it}].insert({i, *last});
				}
				it++;
			}
		}
	}

	vector<vector<int>> dist(n+1, vector<int>(360, 1e9+1)); 
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
	
	dist[ini.first][ini.second] = 0;
	pq.push({0, ini});
	
	while(!pq.empty()){
		auto [du, u] = pq.top(); pq.pop();

		if(du != dist[u.first][u.second]) continue;

		for(auto v : m[u]){
			int dis = 0;
			if(v.first == u.first) 
				dis = vel[u.first]*min(abs(v.second - u.second), 360 - abs(v.second - u.second));
				
			if(du + dis < dist[v.first][v.second]){
				dist[v.first][v.second] = du + dis;
				pq.push({du + dis, v});
			}
		}
	}
	cout << (dist[fin.first][fin.second] >= 1e9+1 ? "IMPOSIBLE" : to_string(dist[fin.first][fin.second])) << "\n";
}

/*
2
3 4
1 20
1 350
2 170
2 185
10 10 10
1 0 3 170

4 2
1 90
3 0
10 20 30 40
3 90 1 0
*/

int main(){
	int tt; cin >> tt; while(tt--) solve();
}