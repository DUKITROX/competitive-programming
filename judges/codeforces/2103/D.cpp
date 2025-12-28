#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n; queue<pair<int,int>> q;
	vector<set<int>> adj(n);
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		q.push({a,i});
	}

	int it = 1, ant=-1;
	vector<int> inDeg(n);
	int cont = 0;
	while(q.size() > 1 && cont++ < 1e2){
		int l = q.size();
		unordered_set<int> yellow;
		vector<int> elim;
		for(int i = 0; i < l; i++){
			pair<int,int> u = q.front(); q.pop();
			if(u.first > it || u.first == -1){ // safe
				if(it%2){ // min
					if(i) {adj[u.second].insert(ant); inDeg[ant]++; yellow.insert(ant);}
					if(i != l-1) {adj[u.second].insert(q.front().second); inDeg[q.front().second]++; yellow.insert(q.front().second);}
					q.push(u);
				}else{ // max
					if(i) {adj[ant].insert(u.second); inDeg[u.second]++; yellow.insert(ant);}
					if(i != l-1) {adj[q.front().second].insert(u.second); inDeg[u.second]++; yellow.insert(q.front().second);}
					q.push(u);
				}
			}else{ // delete this node
				elim.push_back(u.second);
			}
			ant = u.second;
			for(int i = 0; i < (int)elim.size()-1; i++){ //forward pass
				if(yellow.count(elim[i]) && !yellow.count(elim[i+1])){
					if(it%2){ // min
						adj[elim[i]].insert(elim[i+1]);
					}else{ // max
						adj[elim[i+1]].insert(elim[i]);
					}
					yellow.insert(elim[i+1]);
				}
			}
			for(int i = (int)elim.size()-1; i > 0; i--){ //backwards pass
				if(yellow.count(elim[i]) && !yellow.count(elim[i-1])){
					if(it%2){ // min
						adj[elim[i]].insert(elim[i-1]);
					}else{ // max
						adj[elim[i-1]].insert(elim[i]);
					}
					//cout << "yellow " << elim[i] << " -> " << elim[i-1] << endl;
					yellow.insert(elim[i-1]);
				}
			}
		}
		it++;
	}
	vector<int> sol;
	vector<bool> vis(n);
	cont = 0;
	auto dfs = [&](auto&& self, int u)->void{
		vis[u] = true;
		for(auto v : adj[u]){
			if(!vis[v]) self(self, v);
		}
		assert(cont++ < 1e2);
		sol.push_back(u);
	};
	for(int i = 0; i < n; i++){
		if(!inDeg[i] && !vis[i]) dfs(dfs, i);
	}
	reverse(sol.begin(), sol.end());
	vector<int> SOL(n);
	// cout << sol.size() << endl;
	for(int i = 0; i < n; i++){
		SOL[sol[i]] = i+1;
	}
	for(int i = 0; i < n; i++){
		cout << SOL[i] << " ";
	}
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

