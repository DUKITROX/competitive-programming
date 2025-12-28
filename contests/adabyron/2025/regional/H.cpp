#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	auto start = chrono::high_resolution_clock::now();

	int N = 5*1e6+100;
	vector<int> pat(N); pat[1] = 2; pat[0] = 1;
	for(int i = 2; i <= N-10; i++) pat[i] = ((pat[i-1] + (i&1?1:-1))<<1)%MOD;

	string s; while(cin >> s){
		int64_t n = s.size()>>1, m = 1, ind = 0;
		if(n==1){cout << "1 1\n"; continue;}

		stack<int> stk;
		vector<vector<int>> adj(n);
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '('){
				if(stk.empty()){ m *= (m==1?3:2); m%=MOD;}
				stk.push(ind++);
			}else{
				int v = stk.top(); stk.pop();
				if(!stk.empty()) 
					adj[stk.top()].push_back(v);
			}
		}
		bool impar = true;
		for(auto u : adj){
			if(u.size() % 2 == 0 && u.size() > 0) impar = false;
			m *= pat[u.size()]; m %= MOD;
		}
		if(impar) {cout << "2 2\n"; continue;}
		cout << "3 " << m << "\n";
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	#ifndef LOCAL
	cout << setprecision(3) << fixed << "Time: " << elapsed_seconds.count() << " seconds\n";
	#endif
}

