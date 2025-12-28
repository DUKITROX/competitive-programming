#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; while(getline(cin, s)){
		stack<char> stk; bool ok = true;
		for(int i = 0; i < s.length() && ok; i++){
			if(s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
			else if (s[i] == ')'){
				if(!stk.empty() && stk.top() == '(') stk.pop();
				else ok = false;
			}else if(s[i] == ']'){
				if(!stk.empty() && stk.top() == '[') stk.pop();
				else ok = false;
			}else if(s[i] == '}'){
				if(!stk.empty() && stk.top() == '{') stk.pop();
				else ok = false;
			}
		}
		cout << (ok && stk.empty() ? "YES" : "NO") << "\n";
	}
}

