#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; while(cin >> n){
		vector<int> arr;
		for(int i = 0; i < n; i++){
			int a, l = 0, r = arr.size()-1, m, ans = -1;
			cin >> a;
			while(l <= r){
				m = (r+l)/2;
				if(arr[m] <= a){
					l = m+1;
				} else{
					r = m-1;
					ans = m;
				}
			}
			
			if(ans == -1)
				arr.push_back(a);
			else 
				arr[ans] = a;
		}
		cout << arr.size() << "\n";
	}
}
