#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct dynamic{
	int N, T, it, num_comp;
	vector<int> p;
	stack<pair<int,int>> stk; 
	vector<vector<pair<int,int>>> seg;
 
	dynamic(int n, int t){ 
		N = num_comp = n;
		p.assign(N,-1);
 
		T = t;
		while(__builtin_popcount(T) != 1) T++;
		seg.resize(T<<1);
	}
	void add_edge(int qL, int qR, int L, int R, int node, pair<int,int> edge){
		if(qL <= L && R <= qR) seg[node].push_back(edge);
		else if(qR < L || R < qL) return;
		else{
			int M = (L+R)/2;
			add_edge(qL, qR, L, M, node<<1, edge);
			add_edge(qL, qR, M+1, R, (node<<1)+1, edge);
		}
	}
	void add_edge(int qL, int qR, pair<int,int> edge){ // add edge in [qL, qR] conf.
		add_edge(qL, qR, 0, T-1, 1, edge);
	}
	void set(int t){ // set to i_th configuration
		num_comp = N;
		it = T+t;
		p.assign(N, -1);
		stk = stack<pair<int,int>>();
 
		int L = 0, R = T-1;
 		for(int i = 1; i < (T<<1);){
			for(auto e : seg[i])
				merge(e.first, e.second);
 
			int M = ((R-L)>>1) + L;
			i <<= 1;
			if(t > M){
				L = M+1;
				i++;
			}else{
				R = M;
			}
		}
	}
	bool next(){ // advance to next configuration
		if(it >= (T<<1)-1) return false;
		int cur = it++;
		while(cur & 1){
			roll_back(seg[cur].size());
			cur >>= 1;
		}
 
		roll_back(seg[cur++].size());
 
		while(cur < (T<<1)){
			for(auto e : seg[cur])
				merge(e.first, e.second);
			cur <<= 1;
		}
		return true;
	}
	int find(int x){return (p[x] < 0 ? x : find(p[x]));}
	void merge(int x, int y){
		int i = find(x), j = find(y);
		if(i == j){
			stk.push({i,0});
		}else{
			if(p[i] < p[j]) swap(i,j);
			stk.push({i, p[i]});
			p[j] += p[i]; p[i] = j;
			num_comp--;
		}
	}
	int size(int x){
		return -p[find(x)];
	}
	void roll_back(int n){
		while(n-- && !stk.empty()){
			auto[x, y] = stk.top(); stk.pop();
			num_comp++;
			p[p[x]] -= y;
			p[x] = y;
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int A,N,M,E,T,B,K; cin >> A >> N >> M >> E >> T >> B;
	vector<int> bobby(B); for(auto& b : bobby) cin >> b; cin >> K;

	vector<vector<int>> adj(N), pos(A+1, vector<int>(N, INF));
	vector<pair<int,int>> edges(T);
	dynamic dt(N,T);

	for(int i = 0; i < T; i++) {
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

		edges[i] = {u,v};
		dt.add_edge(i, i+M-1, edges[i]);
	}
	for(int i = 0; i < A; i++) pos[i][i] = 0;

	auto bfs = [&] (pair<int,int>& node, int& per, int& time) -> void{
		queue<int> q;
		if(pos[per][node.first] != INF) q.push(node.first);
		if(pos[per][node.second] != INF) q.push(node.second);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for(auto v : adj[u]){
				if(pos[per][v] == INF && dt.find(u) == dt.find(v)){
					pos[per][v] = time;
					q.push(v);
				}
			}
		}
	};
	dt.set(0);
	for(int i = 0; i < T; i++, dt.next()){
		if(dt.size(edges[i].first) > K){
			for(int& b : bobby){
				if(dt.find(b) == dt.find(edges[i].first)){
					pos[A][edges[i].first] = min(pos[A][edges[i].first], i);
					break;
				}
			}
		}
		bfs(edges[i], A, i);
		for(int j = 0; j < A; j++)
			if(pos[j][edges[i].first] != INF|| pos[j][edges[i].second] != INF)
				bfs(edges[i], j, i);
	}

	for(int i = 0; i < A; i++){
		int sol = INF;
		for(int j = N-1; j >= N-E; j--)
			if(pos[i][j] < pos[A][j])
				sol = min(sol, pos[i][j]);
		cout << (sol == INF ? "IMPOSSIBLE" : to_string(sol)) << "\n";
	}
}

