#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
int cont = 0;

void upd(int m, int M, int anc, map<ll,set<ll>>& m1, map<ll,set<ll>>& m2){
	auto it = m1[anc].lower_bound(m);
	while(it != m1[anc].end() && *it <= M){
		cont++;
		m2[*it].erase(anc);
		it = m1[anc].erase(it);
	}
}

void solve(){
	int n,m,x,y; cin >> n >> m >> x >> y; x--; y--;

	map<ll ,set<ll>> Xs;
	map<ll,set<ll>> Ys;

	for(int i = 0; i < n; i++){
		int a,b; cin >> a >> b; a--; b--;
		Xs[a].insert(b);
		Ys[b].insert(a);
	}
	for(int i = 0; i < m; i++){
		char d; int c; cin >> d >> c;
		if(d=='D'){
			y-=c;
			upd(y,y+c,x,Xs,Ys);
		}else if(d=='U'){
			y += c;
			upd(y-c,y,x,Xs,Ys);
		}else if(d=='L'){
			x -= c;
			upd(x,x+c,y,Ys,Xs);
		}else{
			x += c;
			upd(x-c,x,y,Ys,Xs);
		}
	}

	cout << x+1 << " " << y+1 << " " << cont << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
