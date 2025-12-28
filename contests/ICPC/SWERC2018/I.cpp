#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int x4[] = {0,1,0,-1};
int y4[] = {1,0,-1,0};

int x8[] = {-1,0,1,1,1,0,-1,-1};
int y8[] = {1,1,1,0,-1,-1,-1,0};

int main(){
	int W,H; cin >> W >> H;
	vector<string> stone(H); for(int i = 0; i < H; i++) cin >> stone[i];
	vector<vector<int>> color(H, vector<int>(W,0));
	vector<bitset<1000>> gen(H);

	auto n4 = [&](ii s, int i)->ii{return {max(0,min(s.first+x4[i],H-1)), max(0,min(s.second+y4[i],W-1))};};
	auto n8 = [&](ii s, int i)->ii{return {max(0,min(s.first+x8[i],H-1)), max(0,min(s.second+y8[i],W-1))};};
	auto check = [&](ii s, int ch, int co)->bool{char c=stone[s.first][s.second];int l=color[s.first][s.second];
							return !((gen[s.first][s.second])||(ch==1&&c!='.')||(ch==-1&&c!='#')||(l!=0&&co!=l));};
	auto flood = [&](ii s, int ch, int co, bool e, bool g=false)->void{
		vector<bitset<1000>> v(H);
		queue<ii> q; q.push(s); v[s.first][s.second] = true; color[s.first][s.second] = co;

		while(!q.empty()){
			ii V = q.front();q.pop();
			if(g) gen[V.first][V.second] = true;

			for(int i = 0; i < (e?8:4); i++){
				ii u = (e?n8(V,i):n4(V,i));
				if(check(u,ch,co) && !v[u.first][u.second] && !gen[u.first][u.second]){
					color[u.first][u.second] = co;
					v[u.first][u.second] = true;
					q.push(u);
				}
			}
		}
	};
	
	flood({0,0}, -1, -1, 1, 1);
	
	int COL = 1;
	map<int,int> count;

	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(color[i][j] == 0){
				flood({i,j}, 0, COL++, 0);
				flood({i,j},1,color[i][j],0);
			}else if(color[i][j] > 0 && !gen[i][j] && stone[i][j] == '.'){
				count[color[i][j]]++;
				flood({i,j},1,color[i][j],0,1);
			}
		}
	}
	int A = 0, B = 0, C = 0;
	for(auto &[f,s] : count){
		if(s == 1) C++;
		else if(s == 2) A++;
		else B++;
	}
	cout << A << " " << B << " " << C << endl;
}
