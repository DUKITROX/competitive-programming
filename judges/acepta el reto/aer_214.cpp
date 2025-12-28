#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; while(cin >> n && n){
		map<string, int> m;
		for(int i = 0; i < n; i++){string s; cin >> s; m[s]++;}
		int q; cin >> q; for(int i = 0; i < q; i++){string s; cin >> s; cout << ++m[s] << "\n";}
		cout << "\n";
	}
}
