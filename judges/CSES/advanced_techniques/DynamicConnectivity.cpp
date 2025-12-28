#include <bits/stdc++.h>
using namespace std;

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
	void next(){ // advance to next configuration
		if(it >= (T<<1)-1) return;

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
 
	int find(int x){return (p[x] < 0 ? x : find(p[x]));}
	void merge(int x, int y){
		int i = find(x), j = find(y);
		if(i == j){
			stk.push({-1,-1});
		}else{
			if(p[i] < p[j]) swap(i,j);
			stk.push({i, p[i]});
			p[j] += p[i]; p[i] = j;
			num_comp--;
		}
	}
	void roll_back(int n){
		while(n-- && !stk.empty()){
			auto[x, y] = stk.top(); stk.pop();
			if(x == -1) continue;
			num_comp++;
			p[p[x]] -= y;
			p[x] = y;
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,q; cin >> n >> m >> q;

	dynamic dt(n, q+1);
	set<pair<int,int>> edge_order;
	vector<pair<pair<int,int>,pair<int,int>>> edges;

	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v; u--; v--;

		if(!edge_order.count({u,v}) && !edge_order.count({v,u}))
			edge_order.insert({u,v});
		else if(edge_order.count({v,u}))
			swap(u,v);

		edges.push_back({{0,0},{u,v}});
	}

	for(int i = 1; i <= q; i++){
		int a, u, v; cin >> a >> u >> v; u--; v--;

		if(!edge_order.count({u,v}) && !edge_order.count({v,u}))
			edge_order.insert({u,v});
		else if(edge_order.count({v,u}))
			swap(u,v);

		if(a == 1) // add
			edges.push_back({{i,0},{u,v}});
		else // remove
			edges.push_back({{i,1},{u,v}});
	}
	sort(edges.begin(), edges.end());

	map<pair<int,int>, int> active;
	for(int i = 0; i < edges.size(); i++){
		if(!edges[i].first.second){ // add
			if(active.find(edges[i].second) == active.end())
				active[edges[i].second] = edges[i].first.first;
		}else{ // remove
			if(active.find(edges[i].second) != active.end()){
				int ini = active[edges[i].second];
				int fin = edges[i].first.first - 1;
				dt.add_edge(ini, fin, edges[i].second);
				active.erase(edges[i].second);
			}
		}
	}

	for(auto& e : active){
		dt.add_edge(e.second, q, e.first);
	}
	auto dfs = [&](auto&& self, int u)->void{
		for(auto e : dt.seg[u])
			dt.merge(e.first, e.second);

		if(u >= dt.T){
			int i = u - dt.T;
			if(i<=q)
				cout << dt.num_comp << " \n"[i == q];
		}else{
			self(self, u*2);
			self(self, u*2+1);
		}
		dt.roll_back(dt.seg[u].size());
	};

	dfs(dfs, 1);
}
