#include <bits/stdc++.h>
using namespace std;

int dp(int i, int j, int l, string& s, string& p, int memo[21][21]){
	if(i == s.length())	{
		if(j > l) return 1;
		else return 0;
	}
	if(j == p.length()) return 0;
	if(memo[i][j] != -1) return memo[i][j];
	
	int& ans = memo[i][j] = 0;
	if(p[j] == '#' || isupper(p[j])){
		if(s[i] == tolower(p[j]) || p[j] == '#'){
			ans |= dp(i+1, j, l, s, p, memo);
			ans |= dp(i+1, j+1, l, s, p, memo);
		}
		ans |= 	dp(i, j+1, l, s, p, memo);
	}else{
		if(s[i] == p[j] || p[j] == '.'){
			ans |= dp(i+1, j+1, l, s, p, memo);
		}
	}
	return ans;
}

class Solution{
public:
	bool isMatch(string S, string P){
		string p = "";
		int memo[21][21], l = -1; memset(memo, -1, sizeof memo);

		for(int i = P.length()-1; i>=0; i--){
			if(P[i] == '*'){
				if(P[i-1] == '.') p += '#';
				else p += toupper(P[i-1]);
				i--;
			} else p += P[i];
		} reverse(p.begin(), p.end()); for(int i = 0; i < p.size(); i++) if(islower(p[i]) || p[i] == '.') l = i;
		
		cout << S << " " << p << " " << l << endl;
		return (dp(0,0,l,S,p,memo) == 1);
	}
};

int main(){
	Solution sol; string S,P; cin >> S >> P;
	cout << sol.isMatch(S,P) << "\n";
}
