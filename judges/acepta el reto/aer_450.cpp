#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		int N, R, key[10], msg[250000];
		queue<int> q;
		cin >> N >> R;
		for(int i = 0; i < N; i++) cin >> key[i];
		for(int i = 0; i < R; i++){
			cin >> msg[i];
			if(msg[i] == key[0]){
				q.push(i);
			}
		}
		int m = R;
		while(!q.empty()){
			int i = q.front(); q.pop();
			i++;
			int j = 1, M = 1;;
			for(; i < R; i++){
				M++;
				if(M > m) break;
				if(msg[i] == key[j]){
					j++;
					if(j == N){
						m = min(m,M);
						break;
					}
				}
			}
		}
		cout << m << "\n";
	}
}
