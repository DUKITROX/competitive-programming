#include <bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));
	int t = 1000;
	cout << t << endl;
	for(int i = 0; i < t; i++){
		int n = rand()%100 + 1;
		cout << n << endl;
		for(int j = 0; j < n; j++){
			int c = rand()%2;
			if(c){
				int l = rand()%20 + 1;
				int a1 = rand()%360, a2 = rand()%360;
				cout << "C " << l << " " << a1 << " " << a2 << endl;
			}else{
				int l1 = rand()%20 + 1, l2 = rand()%20 + 1; if(l1==l2) continue;
				int a = rand()%360; 
				cout << "S" << " " << min(l1,l2) << " " << max(l1,l2) << " " << a << endl;
			}
		}
	}
}
