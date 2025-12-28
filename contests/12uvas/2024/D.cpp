#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; while(cin >> n && n){
		map<int,int> low,high;
		for(int i = 0; i < n; i++){
			int c; cin >> c;
			if(low.find(c) == low.end()){
				low[c] = i; high[c] = i;
			}else high[c] = i;
		}
		long long sum = 0;
		for(auto& e : low){
			sum += high[e.first] - e.second;
		}
		cout << sum << "\n";
	}
}
