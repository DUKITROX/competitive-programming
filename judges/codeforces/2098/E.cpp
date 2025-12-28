#include <bits/stdc++.h>
using namespace std;

template<typename T>
T extgcd(T a, T b, T &x, T &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	T p = b / a;
	T g = extgcd(b - p * a, a, y, x);
	x -= p * y;
	return g;
}

/*
   ax + by = c
   g = gcd(a,b)
   x,y possible solution
 */
template<typename T>
bool diophantine(T a, T b, T c, T &x, T &y, T &g) { 
	if (a == 0 && b == 0) {
		if (c == 0) {
			x = y = g = 0;
			return true;
		}
		return false;
	}
	if (a == 0) {
		if (c % b == 0) {
			x = 0;
			y = c / b;
			g = abs(b);
			return true;
		}
		return false;
	}
	if (b == 0) {
		if (c % a == 0) {
			x = c / a;
			y = 0;
			g = abs(a);
			return true;
		}
		return false;
	}
	g = extgcd(a, b, x, y);
	if (c % g != 0) {
		return false;
	}
	T dx = c / a;
	c -= dx * a;
	T dy = c / b;
	c -= dy * b;
	x = dx + (T) ((__int128) x * (c / g) % b);
	y = dy + (T) ((__int128) y * (c / g) % a);
	g = abs(g);
	return true;
}

void solve(){
	int n,x,y,vx,vy; cin >> n >> x >> y >> vx >> vy;	
	int g = gcd(vx,vy); x/=g; y/=g;
	int k,l,a,b;
	if(diophantine(-vx, n, -x, a, k, g) && diophantine(-vy, n, -y, b, l, g)){
		if(l <= 0 || k <= 0) cout << "AAAA\n";
	}else cout << "-1\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

