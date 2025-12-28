#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a,b;
	vector<long long> a1,a2;
	while(cin >> a >> b){
		a1.push_back(a);
		a2.push_back(b);
	}
	sort(a1.begin(), a1.end());
	sort(a2.begin(),a2.end());
	long long sum = 0;
	for(int i = 0; i  < a1.size(); i++) sum += abs(a1[i]-a2[i]);
	cout <<"SUM: "<< sum << "\n";
}

int main(){
	solve();
}
