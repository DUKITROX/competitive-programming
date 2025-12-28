#include <bits/stdc++.h>
using namespace std;

int toDist(int x, int y, pair<int,int> p1, pair<int,int> p2, int l, int r){
	cout << l << " " << r << endl;
	if(l==r) return l;
	int nx = p1.first + (p2.first-p1.first+1)/2;
	int ny = p1.second + (p2.second-p2.first+1)/2;

	if(x < nx){
		if(y < ny)
			return toDist(x,y,p1,{nx-1,ny-1},l,r - 3*((l-r)/4));
		else
			return toDist(x,y,{p1.first,ny}, {nx-1, p2.second}, l + 3*((l-r)/4), r);
	}else{
		if(y < ny)
			return toDist(x,y,{nx, p1.first},{p2.first,ny-1},l + 2*((l-r)/4), r - (l-r)/4);
		else
			return toDist(x,y,{nx,ny}, p2, l + ((l-r)/4), r - 2*((l-r)/4));
	}
}

pair<int,int> toCoord(int d, int l, int r, pair<int,int> p1, pair<int,int> p2){
	int m = (r-l-1)>>2, cuad = 0;
	while(1){
		if(d < l+m){
			break;
		}else{
			l += m;
			cuad++;
		}
	}
}

void solve(){
	int n,q; cin >> n >> q;
	for(int i = 0; i < q; i++){
		string s; cin >> s;
		if(s == "->"){
			int x,y; cin >> x >> y;
			cout << toDist(x,y,{1,1}, {1<<n,1<<n}, 1, 1<<(2*n));
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
