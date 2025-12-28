vector<int> colores(200000), tamaños(200000);
vector<vector<int>> adj(200000);
vector<set<int>> conjuntos;

int merge(int i, int j){
	if(conjuntos[i].size() > conjuntos[j].size())
		swap(i,j);
	for(auto e : conjuntos[i])
		conjuntos[j].insert(e);
	conjuntos[i].clear();
	return j;
}

int dfs(int u, int p){
	int s = u;
	conjuntos[s].insert(colores[u]);

	for(auto v : adj[u])
		if(v != p)
			s = merge(s, dfs(v,u));

	tamaños[u] = conjuntos[s].size();
	return s;
}
