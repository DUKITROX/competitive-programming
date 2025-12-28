#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 

void solve(){
	int X,Y,N; cin >> X >> Y >> N;
	vector<pair<int,int>> arr(N); for(int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
		
	int l = 0, r = Y-1; long long sol = 1e18;
	while(l <= r){
		int azul = 0, rojo = 0;
		int m = (r+l)/2;
		ll s = 0;

		for(int i = 0; i < N; i++){
			pair<int,int> p1 = arr[i], p2 = arr[i];
			while(i < N-1 && arr[i+1].first == arr[i].first)
				p2 = arr[++i];
			if(m < p1.second){
				s += 2*(p2.second - m);
				rojo++;
			}else if(m > p2.second){
				s += 2*(m - p1.second);
				azul++;
			}else{
				s += 2*(p2.second - p1.second);
			}
		}
		sol = min(sol,s);
		if(azul > rojo){ // mas arriba que abajo
			r = m-1; 
		}else if (azul < rojo){
			l = m+1;
		}else{
			break;
		}
	}
	cout << sol+X-1 << "\n";
}

int main(){
	solve();
}
