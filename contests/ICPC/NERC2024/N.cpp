#include <bits/stdc++.h>
using namespace std;

int main(){
	int tt; cin >> tt; while(tt--){
		string s; cin >> s;
		if(s[1] == '='){
			if(s[0] != s[2]) s[0] = s[2];
		}else if(s[1] == '<'){
			if(s[0] >= s[2]){
				if(s[2] == '0') s[2] = '9';
				else s[0] = '0';
			}
		}else if(s[1] == '>'){
			if(s[0] <= s[2]){
				if(s[0] == '0') s[0] = '9';
				else s[2] = '0';
			}
		}
		cout << s << "\n";
	}
}
