#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const vector<pair<int, int>> knightMoves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},{-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
const vector<pair<int, int>> kingMoves = {{-1, -1}, {-1, 0}, {-1, 1},{ 0, -1},{ 0, 1},{ 1, -1}, { 1, 0}, { 1, 1}};

void solve(){
	char c;
	string s = "";
	while (cin.get(c) && c != '\n') {
		s += c;
	}
	vector<vector<int>> tam(8, vector<int>(8,0));
	int I=0,J=0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '/'){
			I++;
			J=0;
		}else{
			if(s[i] <= '9' && s[i] >= '0'){
				J += s[i] - '0';
			}else{
				tam[I][J] = 2;
				J++;
			}
		}
	}
	I=J=0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '/'){
			I++;
			J=0;
		}else{
			if(s[i] <= '9' && s[i] >= '0'){
				J += s[i] - '0';
			}else{
				if(s[i] == 'p'){
					if(I<7 && J<7) ckmax(tam[I+1][J+1],1);
					if(I<7 && J>0) ckmax(tam[I+1][J-1],1);
				}else if(s[i] == 'P'){
					if(I>0 && J<7) ckmax(tam[I-1][J+1],1);
					if(I>0 && J>0) ckmax(tam[I-1][J-1],1);
				}else if(s[i] == 'n' || s[i] == 'N'){
					for (size_t m = 0; m < knightMoves.size(); ++m) {
						int di = knightMoves[m].first;
						int dj = knightMoves[m].second;
						int ni = I + di;
						int nj = J + dj;
						if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8) {
							ckmax(tam[ni][nj] , 1);
						}
					}
				}
				if(s[i] == 'r' || s[i] == 'R' || s[i] == 'q' || s[i] == 'Q'){
					int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
					for (int d = 0; d < 4; ++d) {
						int dx = dirs[d][0], dy = dirs[d][1];
						int x = I + dx, y = J + dy;
						while (x >= 0 && x < 8 && y >= 0 && y < 8) {
							if (tam[x][y] == 2) break;
							ckmax(tam[x][y], 1);
							x += dx;
							y += dy;
						}
					}
				}
				if(s[i]  == 'b' || s[i] == 'B'|| s[i] == 'q' || s[i] == 'Q'){
					int dirs[4][2] = {{1,1},{1,-1},{-1,1},{-1,-1}};
					for (int d = 0; d < 4; ++d) {
						int dx = dirs[d][0], dy = dirs[d][1];
						int x = I + dx, y = J + dy;
						while (x >= 0 && x < 8 && y >= 0 && y < 8) {
							if (tam[x][y] == 2) break;
							ckmax(tam[x][y], 1);
							x += dx;
							y += dy;
						}
					}
				}
				if(s[i] == 'k' || s[i] == 'K'){
					for (size_t m = 0; m < kingMoves.size(); ++m) {
						int di = kingMoves[m].first;
						int dj = kingMoves[m].second;
						int ni = I + di;
						int nj = J + dj;
						if (ni >= 0 && ni < 8 && nj >= 0 && nj < 8) {
							ckmax(tam[ni][nj], 1);
						}
					}
				}
				J++;
			}
		}
	}
	int cont = 0;
	for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) cont += tam[i][j] == 0;
	cout << cont << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; cin.ignore(); while(tt--) solve();

}

