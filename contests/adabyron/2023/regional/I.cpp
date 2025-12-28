#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000007;

long long int fact[10];
long long pot[10];

void solve(string n){
	for(int i = 0; i < n.length()/2; i++){
		int x = n[2*i] - '0', y = n[2*i+1] - '0';
		long long r1,r2;
		if(x == 1) r1 = pot[y];
		else r1 = fact[y];

		if(y == 1) r2 = pot[x];
		else r2 = fact[x];
		long long r = ((47*r1)%9999 + r2)%9999;
		r++;
		cout << r;
	}
	cout << "\n";
}

int main(){
	for(int i = 0; i < 10; i++){
		long long id = i, res = 1;
		for(int j = 0; j < 5; j++){
			id *= i;
		}
		pot[i] = id;
		for(int j = id; j > 1; j--){
			res = (res*j)%INF;
		}
		fact[i] = res;
	}
	string n;
	while(cin >> n && n!="0") solve(n);
}
