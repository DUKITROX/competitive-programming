#include <bits/stdc++.h>
using namespace std;

bool can(pair<int,int> p1, pair<int,int> p2){
	int d1 = abs(p1.first-p2.first), d2 = abs(p1.second-p2.second);
	return (sqrt(d1*d1+d2*d2)<=10.0);
}

struct UFDS{
	int n;
	vector<int> p;
	UFDS (int N) : n(N) , p(N, -1){}
	int find(int x) {return (p[x] < 0 ? x : p[x] = find(p[x]));}
	void merge(int x, int y){
		int i = find(x), j = find(y);
		if(i==j) return;
		if(p[i]<p[j]) swap(i,j);
		p[j] += p[i]; p[i] = j;
		n--;
	}
};

int main(){
	int N,M,n; while(cin >> N >> M >> n && N){
		vector<pair<int,int>> arr(n);
		UFDS ufds(n+2);
		for(int k = 0; k < n; k++)	{
			cin >> arr[k].first >> arr[k].second;
			for(int j = 0; j < k; j++){
				if(can(arr[j], arr[k])) ufds.merge(k,j);
			}
			if(can(make_pair(arr[k].first,0), arr[k])) ufds.merge(n,k);
			if(can(make_pair(arr[k].first,N), arr[k])) ufds.merge(n+1,k);
		}
		cout << (ufds.find(n) == ufds.find(n+1) ? "NO" : "SI") << "\n";
	}
}
