#include <bits/stdc++.h>
using namespace std;

struct Dsu {
	int n; vector<int> p;
	Dsu(int n) : n(n), p(n,-1){}
	int find(int x) {return (p[x] < 0 ? x : p[x] = find(p[x]));}
	void merge(int x, int y){
		int i = find(x), j = find(y);
		if(i==j) return;
		if(p[i] < p[j]) swap(i,j);
		p[j]+=p[i];
		p[i] = j;
		n--;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	Dsu dsu(n);
	vector<string> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++){
		string s = "";
		for(int j = 0; j < arr[i].size(); j++){
			if(arr[i][j] == 'u') s += "oo";
			else s += arr[i][j];
		}
		arr[i] = s;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int i1=0,i2=0; bool p = true;
			while(i1 < arr[i].size() && i2 < arr[j].size() && p){
				if(arr[i][i1] == arr[j][i2]){
					i1++;
					i2++;
				}else if(arr[i][i1] == 'u' && i2 < arr[j].size()-1 && arr[j][i2] == 'o' && arr[j][i2+1] == 'o'){
					i1++;
					i2+=2;
				}else if(arr[j][i2] == 'u' && i1 < arr[i].size()-1 && arr[i][i1] == 'o' && arr[i][i1+1] == 'o'){
					i1+=2;
					i2++;
				}else if(arr[j][i2] == 'h' && arr[i][i1] == 'k'){
					while(i1 < arr[i].size()-1 && arr[i][i1] == 'k'){
						i1++;
					}
					if(arr[i][i1] == 'h'){
						i2++;
						i1++;
					}else p = false;
				}else if(arr[i][i1] == 'h' && arr[j][i2] == 'k'){
					while(i2 < arr[j].size()-1 && arr[j][i2] == 'k'){
						i2++;
					}
					if(arr[j][i2] == 'h'){
						i1++;
						i2++;
					}else p = false;
				}else p = false;
			}
			if(i1 == arr[i].size() && i2 == arr[j].size() && p) dsu.merge(i,j);
		}
	}
	cout << dsu.n << "\n";
}
