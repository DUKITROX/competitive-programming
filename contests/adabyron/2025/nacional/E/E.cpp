#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

const double EPS = 1e-7;
const double INF = 1e9;

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


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n,k; while(cin >> n >> k && (n || k)){
		vector<int> arr(n), pre(n); cin >> arr; pre[0] = arr[0];
		for(int i = 1; i <  n; i++) pre[i] = arr[i] + pre[i-1];

		auto check = [&](int t)->bool{
			double lMax = -INF, gMax = -INF, e;
			double prev = -INF;
			for(int i = k; i < n; i++){
				e = arr[i] - t;
				double r1 = pre[i] - pre[i-k] - k*t;
				double r2 = lMax + arr[i] - t;
				lMax = max(r1, r2);
				ckmax(gMax, lMax);
				if(t>=7.0){
					dbg(lMax, gMax);
				}
			}
			if(t >= 7){
				cout << "GM : " << gMax << " ";
				if(gMax >= 0) cout << "SIII";
				cout << endl;
			}
			return (gMax >= 0.0);
		};

		double l = 0.0, r = (double)(*max_element(arr.begin(), arr.end())), ans = 0.0;
		while(abs(l-r) > EPS){
			double m = (l+r)/2;
			if(check(m)){
				ans = m;
				l = m;
			}else{
				r = m;
			}
		}
		cout << fixed << setprecision(3) << ans << "\n";
	}
}
