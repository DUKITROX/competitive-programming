#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; while(cin >> n){
		multiset<int> ms;
		int cont = 0;
		for(int i = 0; i < n; i++){
			int a; cin >> a;
			auto it = ms.upper_bound(a);
			if(it == ms.end()){
				ms.insert(a);
				cont++;
			} else {
				ms.erase(it);
				ms.insert(a);
			}
		}
		cout << cont << "\n";
	}
}
