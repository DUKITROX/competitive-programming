#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b; while(cin >> a >> b && (a||b)){
		vector<int> h(b),c(b);
		for(int i = 0; i < b; i++) cin >> h[i];
		long long sum =0;
		for(int i = 0; i < b; i++){
			int r; cin >> r;
			sum += r;
			if(r > h[i])sum+= INT_MAX;
		}
		cout << (sum<=a?"SI":"NO") << "\n";
	}
}
