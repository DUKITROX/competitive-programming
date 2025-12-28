#include <bits/stdc++.h>
using namespace std;

int CUBOS[4],l,n,mult[] = {1,16,256,4096};
bool vis[70000];

struct nodo{
	int cubos[4],val;
	nodo(int num){
		val = num;
		for(int i = 0; i < n; i++){
			cubos[i] = num%16;
			num/=16;
		}
	}
	int fill(int j){
		int res=0;
		for(int i = 0; i < n; i++){
			if(i == j) res += CUBOS[i]*mult[i];
			else res += cubos[i]*mult[i];
		}
		return res;
	}	
	int empty(int j){
		int res = 0;
		for(int i = 0; i < n; i++){
			if(i == j) res += 0;
			else res += cubos[i]*mult[i];
		}
		return res;
	}
	int swap(int from, int to){
		int res = 0;
		for(int i = 0; i < n; i++){
			if(i == to){
				int d = cubos[to]+cubos[from];
				d = min(CUBOS[to], d);
				res += d*mult[i];
			}else if(i == from){
				int d = CUBOS[to] - cubos[to];
				d = min(cubos[from], d);
				res += d*mult[i];
			}else res+=cubos[i]*mult[i];
		}
		return res;
	}
};

void dfs(int num, bool& pos){
	nodo v(num);
	vis[num] = true;

	for(int i = 0; i < n; i++) if(v.cubos[i] == l) pos = true;

	for(int i = 0; i < n; i++){
		int u = v.fill(i);
		if(!vis[u]) dfs(u, pos);		
	}
	for(int i = 0; i < n; i++){
		int u = v.empty(i);
		if(!vis[u]) dfs(u, pos);
	}
	for(int i = 0; i < n-1; i++){
		for(int j = i; j < n; j++){
			int u = v.swap(i,j);
			if(!vis[u]) dfs(u,pos);

			u = v.swap(j,i);
			if(!vis[u]) dfs(u,pos);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		memset(vis, false, sizeof vis);
		cin >> l;
		if(!l) break;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> CUBOS[i];
		bool pos = false;
		dfs(0,pos);
		cout << (pos?"SI\n":"NO\n");
	}
}
