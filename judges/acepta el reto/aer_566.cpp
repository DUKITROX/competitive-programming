#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define f first
#define s second
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
const int INF = 9;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.f >> p.s; return is;};
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.f << " " << p.s; return os;};
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}

int F,C,N;
int n(int f, int c){return 2*(f*C+c);}

int bfs(int s, int t, vi& parent, vvi& capacity, vvi& adj) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int> > q;
	q.push(make_pair(s,INF));

	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();

		for (int next : adj[cur]) {
			if (parent[next] == -1 && capacity[cur][next]) {
				parent[next] = cur;
				int new_flow = min(flow, capacity[cur][next]);
				if (next == t)
					return new_flow;
				q.push(make_pair(next, new_flow));
			}
		}
	}
	return 0;
}
int maxflow(int s, int t, vvi& capacity, vvi& adj) {
	int flow = 0;
	vector<int> parent(N);
	int new_flow;

	while (new_flow = bfs(s, t, parent, capacity, adj)) {
		flow += new_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			capacity[prev][cur] -= new_flow;
			capacity[cur][prev] += new_flow;
			cur = prev;
		}
	}
	return flow;
}

void solve(){
	cin >> F >> C; N = 2*F*C;
	int s,t;
	ii cap;
	vvi adj(N);
	vvi capacity(N,vi(N));
	for(int i = 0; i < F; i++){
		string s; cin >> s;
		for(int j = 0; j < C; j++){
			if(s[j] == '#') capacity[n(i,j)][n(i,j)+1] = 0;
			else capacity[n(i,j)][n(i,j)+1] = 1;
			if(s[j] == 'C') {s = n(i,j)+1;cap = mp(i,j);}
			else if(s[j] == 'L') t = n(i,j);
		}
	}
	for(int i = 0; i < F-1; i++){
		for(int j = 0; j < C; j++){
			adj[n(i,j)+1].push_back(n(i+1,j));
			adj[n(i+1,j)+1].push_back(n(i,j));
			capacity[n(i,j)+1][n(i+1,j)] = INF;
			capacity[n(i+1,j)+1][n(i,j)] = INF;
		}
	}
	for(int i = 0; i < F; i++){
		for(int j = 0; j < C-1; j++){
			adj[n(i,j)+1].push_back(n(i,j+1));
			adj[n(i,j+1)+1].push_back(n(i,j));
			capacity[n(i,j)+1][n(i,j+1)] = INF;
			capacity[n(i,j+1)+1][n(i,j)] = INF;
		}
	}
	if(cap.f > 0 && capacity[n(cap.f-1,cap.s)][n(cap.f-1,cap.s)+1] != 0) capacity[n(cap.f-1,cap.s)][n(cap.f-1,cap.s)+1] = INF;
	if(cap.f < F-1 && capacity[n(cap.f+1,cap.s)][n(cap.f+1,cap.s)+1] != 0) capacity[n(cap.f+1,cap.s)][n(cap.f+1,cap.s)+1] = INF;
	if(cap.s > 0 && capacity[n(cap.f,cap.s-1)][n(cap.f,cap.s-1)+1] != 0) capacity[n(cap.f,cap.s-1)][n(cap.f,cap.s-1)+1] = INF;
	if(cap.s < C-1 && capacity[n(cap.f,cap.s+1)][n(cap.f,cap.s+1)+1] != 0) capacity[n(cap.f,cap.s+1)][n(cap.f,cap.s+1)+1] = INF;

	int sol = maxflow(s,t,capacity,adj);
	for(int i = 1; i < 2*F*C; i+=2){
		cout << i << " : ";
		for(int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << " ";
		cout << "\n";
	}
	cout << (sol >= INF ? "IMPOSIBLE" : to_string(sol)) << "\n";
}
/*
3
4 5
...C.
...#.
##...
..L..
3 3
C.#
...
#.L
4 6
######
##..##
#.LC.#
######
*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; while(t--)solve();
}