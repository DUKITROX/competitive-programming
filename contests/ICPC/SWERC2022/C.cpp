#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m; cin >> n >> m;
	int ind = -1;
	vector<int> x(n);
	vector<bool> v(m+1,false);
	for(int i = 0; i < n; i++) cin >> x[i];
	sort(x.begin(),x.end(),greater<int>());
	for(int i = 0; i < n && ind == -1; i++) if(m/x[i] < i+1) ind = i;

	// size pos
	if(ind == -1){ //Alice O(n*m))
		cout << "Alessia" << endl;
		for(int i = 0; i < n; i++){
			int cant = 0,j=1;
			for(; j <= m && cant < x[i]; j++)
				cant = (v[j]?0:cant+1);
			cout << x[i] << " " << j - cant << endl; 
			int d; cin >> d; v[d] = true;
		}
	}else{ //Bob
		cout << "Bernardo" << endl;
		for(int i = 0; i < n; i++){
			int pos,len; cin >> len >> pos;
			bool found = false;
			for(int j = pos; j < pos+len; j++) if(v[j]) {cout << j << endl; found = true;}
			if(!found){
				int d;
				if(len < x[ind]) d = pos;
				else{
					d = min((pos/x[ind])*(x[ind])+x[ind], pos+len-1);
					for(int j = 0; j < n; j++){
						if(x[j] == len){
							x.erase(x.begin()+j);
							ind--;
							break;
						}
					}
				}
				cout << d << endl;
				v[d] = true;
			}
		}
	}
}
