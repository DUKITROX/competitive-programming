#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	while(n--){
		string s; cin >> s; vector<int> arr(4,0);
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'W') arr[0]++;
			else if(s[i] == 'D') arr[1]++;
			else if(s[i] == 'S') arr[2]++;
			else arr[3]++;
		}
		for(int i = 0;i < 4; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
}
