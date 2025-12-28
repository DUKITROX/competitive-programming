#include <bits/stdc++.h>
using namespace std;

int X,Y;
int rec(int x, int y, double r){
	int a = (sqrt(abs(x-X)*abs(x-X) + abs(y-Y)*abs(y-Y)) <= r ? 1 : 0);
	if(r<=1) return a; 
	return rec(x,y+r,(int)r/2) + rec(x-r,y,(int)r/2) + rec(x+r, y,(int) r/2) + rec(x, y-r, (int)r/2) + a;
}

bool solve(){
	double r; cin >> r >> X >> Y;
	if(!cin) return false;
	cout << rec(0,0,r) << "\n";
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(solve());
}
