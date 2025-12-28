#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(){
	long long int N = 1<<3;
	unsigned int n;
	int cont = 0;
	for(int n = 0; n < N; n++){
		cont = 0;
		for(int i = 0; i < N; i++){
			if(i == (i*n)%N) cont++;
		}
		cout << n << " : " << cont << " -> " << gcd(n-1, N);
		cout << (cont==gcd(n-1,N) ? "":" ERROR");
		cout << "\n";
	}
}
