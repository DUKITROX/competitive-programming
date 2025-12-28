#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}
void die(string S){puts(S.c_str());exit(0);}

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

void solve(){
	int n; cin >> n;
	vector<pair<int,pair<int,int>>> arr; //[{leftMost x, {length, level i}}]
	vector<int> left(n);
	int L=0,R=1e9+7;
	for(int i = 0; i < n; i++){
		int k,l,r; cin >> k >> l >> r;
		ckmax(L,l);
		ckmin(R,r);
		left[i] = L;

		vector<int> tmp(k); cin >> tmp;

		arr.push_back({r, {0,i}});
		for(int j = 0; j < k; j++){
			int le = tmp[k-1-j];
			arr.push_back({arr.back().first - le, {le,i}});
		}
	}
	dbg(arr);
	sort(arr.begin(), arr.end());
	auto it = arr.begin();
	int sol = max(it->first-L,0);
	dbg(L,it->first,sol);
	while(it != arr.end()){
		auto ini = it, fin = it;
		// [ini, fin)
		while(fin != arr.end() && fin->first == ini->first) fin++;
		sort(ini, fin, [&](const pair<int,pair<int,int>>& p1, const pair<int,pair<int,int>>& p2)->bool{
			return left[p1.second.second] + p1.second.first < left[p2.second.second] + p2.second.first;
		});
		for(;ini!=fin;ini++){
			left[ini->second.second] += ini->second.first;
			int LL = max(L, left[ini->second.second]), RR = min(R,ini->first);
			ckmax(sol, (int)min(R,ini->first) - max(L,left[ini->second.second]));
			dbg(LL,RR,sol);
		}
		it = fin;
	}
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

