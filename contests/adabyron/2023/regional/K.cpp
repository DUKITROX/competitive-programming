#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int casos;
	cin >> casos;
	while(casos--){
		long long n;
		long long b = 1ULL<<32;
		cin >> n;
		if(n%2 == 0) cout << "1\n";
		else{
			cout << gcd(n-1, b) << "\n";
		}
	}
}
