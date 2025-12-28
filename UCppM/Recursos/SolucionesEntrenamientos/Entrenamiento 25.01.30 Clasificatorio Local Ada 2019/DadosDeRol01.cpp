#include <bits/stdc++.h>
using namespace std;

int main(){
	int tt; cin >> tt; while(tt--){
		int a,b,c=0; cin >> a >> b;
		vector<int> frec(a+b+1);
		for(int i = 1; i <= a; i++)
			for(int j = 1; j <= b; j++)
				frec[i+j]++;
		int m = *max_element(frec.begin(), frec.end());
		for(int i = 0; i < a+b+1; i++)
			if(frec[i] == m)
				cout << (!c++ ? to_string(i) : " " + to_string(i));
		cout << "\n";
	}
}
