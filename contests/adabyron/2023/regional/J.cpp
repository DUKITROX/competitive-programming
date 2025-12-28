#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N,M, D;
	cin >> M >> N;
	string mapa[101];
	pair<int,pair<int,int> > hit[10];
	set<int> s;
	for(int i = 0; i < 10; i++) hit[i].second.second = i;
	for(int i = 0; i < N; i++){
		cin >> mapa[i];
		for(int j = 0; j < M; j++){
			if(mapa[i][j] != '.'){
				int id = mapa[i][j] - '0';
				hit[id].second.first++;
				s.insert(id);
			}
		}
	} 
	cin >> D;
	for(int i = 0; i < D; i++){
		int x,y;
		cin >> x >> y;
		int id = mapa[x][y] - '0';
		hit[id].first++;
	}
	sort(hit, hit+10);
	for(int i = 0; i < 10; i++){
		int id = hit[i].second.second;
		if(s.count(id)) {
			cout << id << endl;
			break;
		}
	}
}

int main(){
	solve();
}
