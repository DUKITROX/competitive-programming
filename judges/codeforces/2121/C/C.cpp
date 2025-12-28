#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n,m; cin >> n >> m; vector<vector<int>> arr(n, vector<int>(m)); cin >> arr;
	int M = -1e9;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ckmax(M, arr[i][j]);

	vector<pair<int,int>> par;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++){
			if(arr[i][j] == M) par.push_back({i,j});
		}
	}
	if(par.size() < 3){
		cout << M-1 << "\n";
	}else{
		if(par[0].first == par[1].first)	{
			int c = -1;
			for(auto e : par){
				if(e.first != par[0].first){
					if(c == -1 || e.second == c) c = e.second;
					else{cout << M << "\n"; return;}
				}
			}
			cout << M-1 << "\n";
		}else if(par[0].second == par[1].second){
			int c = -1;
			for(auto e : par){
				if(e.second != par[0].second){
					if(c == -1 || e.first == c) c = e.first;
					else{cout << M << "\n"; return;}
				}
			}
			cout << M-1 << "\n";
		}else{
			int r = par[0].first, c = par[1].second;
			int can = 1;
			for(auto e : par){
				if(e.second != c && e.first != r) can = 0;
			}

			if(can) {cout << M-1 << "\n"; return;}
			can = 1;

			r = par[0].second, c = par[1].first;
			for(auto e : par){
				if(e.second != r && e.first != c) can = 0;
			}

			if(can) cout << M-1 << "\n";
			else cout << M << "\n";
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

