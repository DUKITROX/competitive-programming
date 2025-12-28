#include <bits/stdc++.h>
using namespace std;

struct UFDS{
	int n;
	vector<int> p;
	UFDS(int N) : n(N), p(N, -1){}
	int find(int x){return (p[x] < 0) ? x : p[x] = find(p[x]);}
	void join(int x, int y){
		int i = find(x), j = find(y);
		if(i == j) return;
		if(p[i] < p[j]) swap(i,j);
		p[j] += p[i]; p[i] = j;
		n--;
	}
	int size(int x) {return -p[find(x)];}
};

int N,M,K,n; 

int node(int i, int j){
	return i*(M+1)+j;	
}
int node(pair<int,int> p){
	return p.first*(M+1) + p.second;
}
bool can(pair<int,int> p1, pair<int,int> p2){
	int d1 = abs(p1.first-p2.first), d2 = abs(p1.second-p2.second);
	return (sqrt(d1*d1 + d2*d2) <= (double)K);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> N >> M >> K >> n){
		UFDS ufds((N+1)*(M+1));
		vector<pair<int,int>> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i].first >> arr[i].second;
		}
		reverse(arr.begin(), arr.end());

		set<pair<int,int>> s;
		s.insert({0,0}); s.insert({N,M});
		pair<int,int> sol = {-1,-1};

		for(int i = 0; i < n && sol == make_pair(-1,-1); i++){
			int x = arr[i].first, y = arr[i].second;

			for(int j = max(0,x-K); j <= min(N,x+K); j++){
				for(int k = max(0,y-K); k <= min(M, y+K); k++){
					if(can({j, k}, arr[i]) && s.count({j, k})){
						ufds.join(node(j, k), node(arr[i]));
					}
				}
			}

			s.insert(arr[i]);
			if(ufds.find(node({0,0})) == ufds.find(node(N,M)))
				sol = arr[i];
		}
		if(sol == make_pair(-1,-1))
			cout << "NUNCA SE PUDO\n";
		else
			cout << sol.first << " " << sol.second << "\n";
	}
}
