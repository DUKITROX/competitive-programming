struct DSU{
	int N;
	vector<int> p;
	stack<pair<int,int>> st;
	DSU(int n) : N(n), p(n, -1){}
	int find(int x){return (p[x] < 0 ? x : find(p[x]));}
	bool merge(int x, int y){
		int i = find(x), j = find(y);
		if(i == j) return false;
		if(p[i] < p[j]) swap(i,j);
		st.push({i,p[i]});
		p[j] += p[i]; p[i] = j;
		N--;
		return true;
	}
	void roll_back(int n){
		while(n-- && !st.empty()) {
			N++;
			int i = st.top().first, pi = st.top().second;
			p[p[i]] -= pi;
			p[i] = pi;
			st.pop();
		} 
	}
};
