#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) { for(auto& e : v) is >> e; return is; }
template<class T> ostream& operator<<(ostream& os, vector<T>& v) { for(auto& e : v) os << e << " "; return os; }

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

const int INF = 1e9;

void solve(){
	int n; cin >> n;
	vector<int> fix(2*n); cin >> fix;
	vector<int> arr = fix;

	auto isSorted = [&]()->bool{
		bool ok = true;
		for(int i = 0; i < 2*n && ok; i++) if(arr[i] != i+1) ok = false;
		return ok;
	};
	auto opA = [&]()->void{
		for(int i = 0; i < n; i++){
			swap(arr[2*i], arr[2*i+1]);
		}
	};
	auto opB = [&]()->void{
		for(int i = 0; i < n; i++){
			swap(arr[i], arr[i+n]);
		}
	};

	int res = INF;
	for(int _ = 0; _ < 2; _++){
		int cont = 0, it = 0;
		if(!_){
			while(!isSorted() && it <= 2*n){
				cont++;
				if(it%2) opA();
				else opB();
				it++;
			}
			if(isSorted())
				ckmin(res, cont);
		}else{
			arr = fix;
			while(!isSorted() && it <= 2*n){
				cont++;
				if(it%2) opB();
				else opA();
				it++;
			}
			if(isSorted())
				ckmin(res, cont);
		}
	}

	cout << (res == INF ? -1 : res) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

