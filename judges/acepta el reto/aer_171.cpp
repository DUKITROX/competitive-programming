#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int32_t main(){
	int arr[100000];
	int n; while(cin >> n && n){
		for(int i = 0; i < n; i++) cin >> arr[i];
		int cont = 0, m = -1;
		for(int i = n-1; i >= 0; i--)
			if(ckmax(m, arr[i])) cont++;
		cout << cont << "\n";
	}
}

