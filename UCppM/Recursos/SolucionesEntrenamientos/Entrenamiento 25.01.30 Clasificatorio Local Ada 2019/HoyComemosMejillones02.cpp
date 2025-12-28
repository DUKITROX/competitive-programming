#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; while(cin >> n){
		vector<int> arr;
		for(int i = 0; i < n; i++){
			int a; cin >> a;
			auto it = upper_bound(arr.begin(), arr.end(), a);
			if(it == arr.end()) arr.push_back(a);
			else *it = a;	
		}
		cout << arr.size() << "\n";
	}
}
