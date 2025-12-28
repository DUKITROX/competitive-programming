#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; while(cin >> n && n){
		vector<int> pos, neg;
		vector<bool> yas(n);
		for(int i = 0; i < n; i++){
			int a; cin >> a;
			if(a>0){
				pos.push_back(a);
				yas[i] = true;
			}else neg.push_back(a);
		}
		sort(pos.begin(), pos.end());
		sort(neg.begin(),neg.end(),greater<int>());
		int i = 0, j = 0;
		for(int k = 0; k < n; k++){
			if(yas[k]) cout << pos[i++] << (k==n-1?"":" ");
			else cout << neg[j++] << (k==n-1?"":" ");
		}
		cout << "\n";
	}
}
