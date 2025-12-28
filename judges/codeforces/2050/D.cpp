#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s; cin >> s;
	for(int i = 0; i < s.length(); i++){
		for(int j = max(0,i-9); j < i; j++)	{
			if(s[i]-'0' - i + j > s[j]-'0'){
				char temp = s[i] - i+j;
				for(int k = i; k > j; k--){
					s[k] = s[k-1];
				}
				s[j] = temp;
				break;
			}
		}
	}
	cout << s << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
