#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 998244353;

void solve(){
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 0; i < n-1; i++){
		int u,v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<vector<int>> dp(n, vector<int>(2,1LL));
	auto dfs = [&](auto && self, int u, int p)->void{
		if(u != 0 && adj[u].size() == 1) return;

		vector<int> pers, baj;
		for(auto v : adj[u]){
			if(v != p){
				self(self, v, u);
				dp[v][0] %= MOD; dp[v][1] %= MOD;
				dp[u][1] *= (dp[v][0]%MOD + dp[v][1]%MOD)%MOD; dp[u][1] %= MOD;
				pers.push_back((dp[v][0] + dp[v][1])%MOD);
				baj.push_back(dp[v][0]);
			}
		}
		int N = pers.size(); vector<int> pre(N), suf(N); 
		for(int i = 0; i < N; i++) pre[i] = (i ? (pre[i-1]*pers[i])%MOD : pers[i]%MOD)%MOD;
		for(int i = N-1; i >= 0; i--) suf[i] = (i < N-1 ? (suf[i+1]*pers[i])%MOD : pers[i]%MOD)%MOD;

		dp[u][0] = 0;
		for(int i = 0; i < N; i++){
			int num = baj[i]; num %= MOD;
			if(i) num *= pre[i-1]; num %= MOD;
			if(i<N-1) num *= suf[i+1]; num %= MOD;
			dp[u][0] += num;
		}
	};
	dfs(dfs, 0, -1);
	cout << dp[0][1] << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

