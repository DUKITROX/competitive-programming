#include <bits/stdc++.h>
using namespace std;

int main(){
	int tt; cin >> tt; while(tt--){
		int n,m,k; cin >> n >> m >> k;
		vector<int> h(n); for(int i = 0; i < n; i++) cin >> h[i];
		vector<int> x(n); for(int i = 0; i < n; i++) cin >> x[i];

		int l = 1, r = 1e9+10, mid, sol = -1;
		while(l <= r){
			mid = (l+r)>>1;
			vector<pair<int,int>> in;
			for(int i = 0; i < n; i++){
				int d = m - ceil((double)h[i]/mid);
				if(d >= 0){in.emplace_back(x[i]-d, +1); in.emplace_back(x[i]+d+1,-1);} 
			}
			sort(in.begin(), in.end());
			int cont = 0; bool p = false;
			for(const auto& [f,s] : in){
				cont += s;
				if(cont >= k){
					p = true;
					break;
				}
			}
			if(p){
				sol = mid;
				r = mid-1;
			}else
				l = mid+1;
		}
		cout << sol << "\n";
	}
}
