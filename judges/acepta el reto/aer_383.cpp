#include <bits/stdc++.h>
using namespace std;
int main(){
	int casos;
	cin >> casos;
	while(casos--){
		int m = -1e9, a,s,n;
		cin >> n >> a;
		n--;
		while(n--){
			cin >> s;
			m = max(m, a-s);
			if(s >= a) a = s;
		}
		cout << m << "\n";
	}
}