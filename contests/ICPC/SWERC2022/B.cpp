#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define mp make_pair
#define sort(x) sort(x.begin(), x.end())
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.first >> p.second; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.first << " " << p.second; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

int h;

int dp(int l, int r, vi& arr, vvi& memo){
	if(memo[l][r] != -1) return memo[l][r];
	if(l == r) return memo[l][r] = h;

	int h_lr = max(0, h + 1 - (arr[r] - arr[l])/2 - (arr[r] - arr[l])%2), res = INF;
	for(int m = l; m < r; m++) res = min(res, dp(l,m,arr,memo) + dp(m+1,r,arr,memo) - h_lr);	
	return memo[l][r] = res;
}

void solve(){
	int n; cin >> n >> h; vi arr(n); cin >> arr;
	vvi memo(n, vi(n,-1));
	cout << dp(0,n-1,arr,memo) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
