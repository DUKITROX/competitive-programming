#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve(){

}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int W,H,N; while(cin >> W >> H >> N && (W || H || N)){

		vector<pair<int,pair<int,int>>> arr(N);
		for(int i = 0; i < N; i++){
			char c; cin >> c;
			if(c == 'G'){
				int a,b; arr[i] = {b,{a,a}};
			}else{
				int a,b,c,d; cin >> a >> b >> c >> d;
				arr[i] = {b,{a,a+c}};
			}
		}
		sort(arr.begin(),arr.end(),[&](pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2)->bool{
			return p1.first > p2.first || p1.first == p2.first && p2.second.first < p2.second.first;
		});

		map<int,int> m; m[1] = W;
		int sol = W*(H-arr[0].first);

		for(int i = 0; i < N, i++){
			//izq
			auto it = m.lower_bound(arr[i].second.first);
			if(it != m.end()){
				int prov = (H-(*it).first) * (arr[i].second.first - (*it).first);
			}
		}
	}
}
