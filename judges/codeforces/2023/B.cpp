#include <bits/stdc++.h>
#define int long long 
using namespace std;

template<typename T> istream& operator>>(istream& is, vector<T>& v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
const int INF = 1e18;

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n); cin >> a >> b;

	vector<long long> prefix(n); prefix[0] = a[0]; for(int i = 1; i < n; i++) prefix[i] = prefix[i-1]+a[i];

	vector<int> d(n,INF); d[0] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
	q.push(make_pair(0,0));
	while(!q.empty()){
		int v = q.top().second, d_v = q.top().first; q.pop();
		if(d_v != d[v]) continue;
		
		if(v != 0 && d[v] < d[v-1]){
			d[v-1] = d[v];
			q.push(make_pair(d[v-1], v-1));
		}
		if(b[v]-1 > v && d[b[v]-1] > d[v] + a[v]){
			d[b[v]-1] = d[v] + a[v];
			q.push(make_pair(d[b[v]-1], b[v]-1));
		}
	}
	long long sol = -INF;
	for(int i = 0; i < n; i++) sol = max(sol, prefix[i] - d[i]);
	cout << sol << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--)solve();
}
