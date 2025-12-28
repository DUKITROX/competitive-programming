#include <bits/stdc++.h>
using namespace std;

void solve(){

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n && n){
		vector<pair<int,int>> arr;
		for(int i = 0; i < n; i++){
			int a,b; cin >> a >> b;
			arr.push_back({a,b});
		}

		int i = 0, act=0, sol=0;
		int b; while(cin >> b && b){
			while(i < n && arr[i].second < b){
				i++;		
			}
			if((i<n && arr[i].first > b) || i >= n) sol++;
		}
		cout << sol << "\n";
	}
}
