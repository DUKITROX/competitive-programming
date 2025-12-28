#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,s1,s2; cin >> s >> s1 >> s2;
	vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false)); 
	dp[0][0] = true;
	for(int i = 0; i <= s1.size(); i++)
		for(int j = 0; j <= s2.size(); j++){
			if(i < s1.size() && s1[i] == s[i+j]) dp[i+1][j] = dp[i+1][j] | dp[i][j];
			if(j < s2.size() && s2[j] == s[i+j]) dp[i][j+1] = dp[i][j+1] | dp[i][j];
		}
	cout << (dp[s1.size()][s2.size()] ? "yes" : "no") << "\n";
}
