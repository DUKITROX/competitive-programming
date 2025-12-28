#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a; while(cin >> a  && a){
		int n; cin >> n; long long sum = 0; for(int i = 0; i < n; i++){
			int b; cin >> b; sum += b;
		}
		cout << sum/a + (sum%a!=0) << "\n";
	}
}
