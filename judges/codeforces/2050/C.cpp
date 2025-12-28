#include <bits/stdc++.h>
using namespace std;

void solve(){
	int dos=0,tres=0;
	string s; cin >> s;
	long long sum = 0;
	for(int i = 0; i < s.length(); i++){
		sum += s[i]-'0';
		if(s[i]=='2') dos++;
		if(s[i]=='3') tres++;
	}
	bool pos = (sum%9==0);
	
	int nec = (sum%9);
	int nic = (nec==0?0:4-(nec/2) + (nec%2?0:5)) ; nic <<= 1;

	while(tres>0 && nic-6 >= 0){nic-=6;tres--;}
	while(dos>0 && nic-2>=0){nic-=2;dos--;}

	cout << (nic==0?"YES":"NO") << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--) solve();
}
