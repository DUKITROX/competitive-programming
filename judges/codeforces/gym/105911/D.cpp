/*
Problem: Virtuous Pope
*/
#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,a,b,c; cin >> n >> a >> b >> c;
	vector<pair<int,int>> x,y,z;
	for(int i = 0; i < n; i++){
		int x1,x2,y1,y2,z1,z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		x.push_back({min(x1,x2),1}); x.push_back({max(x1,x2)+1,-1});
		y.push_back({min(y1,y2),1}); y.push_back({max(y1,y2)+1,-1});
		z.push_back({min(z1,z2),1}); z.push_back({max(z1,z2)+1,-1});
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	int sol = 0, cont = 0;
	for(auto e : x) ckmax(sol, cont += e.second);
	for(auto e : y) ckmax(sol, cont += e.second);
	for(auto e : z) ckmax(sol, cont += e.second);
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

