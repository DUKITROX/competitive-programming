#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long a;
	while(cin >> a && a){
		long long sol = 0, s;
		sol += a; s = a;
		while(cin >> a && a){
			sol += max(0LL, a-(sol-s));
			s = a;
		}
		cout << sol << "\n";
	}
}
