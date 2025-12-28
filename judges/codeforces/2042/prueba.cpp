#include <bits/stdc++.h>
using namespace std;

int main(){
	set<pair<int,int>,greater<>> s;
	s.insert({1,2}); s.insert({4,5}); s.insert({3,9});
	for(auto [f,s] : s){
		cout << f << endl;
	}
	cout << (*s.lower_bound({3,9})).first << endl;
}
