#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long int ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vector<ll> > vvi;
typedef vector<vector<pair<ll,ll> > > vvpii;

void dijkstra(int s, vvpii &adjList, vi &dist) {
	dist.assign(adjList.size(), INT_MAX);
	dist[s] = 0;
	priority_queue<pii, vpii, greater<pii> > pq; pq.push(pii(0, s));
	while (!pq.empty()) {
		pii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (int j = 0; j < adjList[u].size(); j++) {
			pii v = adjList[u][j];
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				pq.push(pii(dist[v.second], v.second));
			}
		}
	}
}

struct SegmentTree {
	vector<ll> st;
	ll n, neutral = 1e18;
	ll op(ll a, ll b){return min(a,b);}
	int l (int v){return v<<1;} 
	int r (int v){return (v<<1)+1;}
	SegmentTree(int N){
		n = N;
		while(__builtin_popcount(n) != 1) n++;
		st.resize(n<<1, neutral);
	}
	ll q(int node, int L, int R, int ql, int qr){
		if(ql <= L && R <= qr) return st[node];
		if(L > qr || R < ql) return neutral;
		ll mid = (L+R)/2;
		return (op(q(l(node), L, mid, ql, qr), q(r(node), mid+1, R, ql, qr)));
	}
	ll q(int ql, int qr){
		return q(1, 0, n-1, ql, qr);
	}
	void update(int node, ll val){
		int ind = node+n;
		st[ind] = val;
		for(int i = ind/2; i > 0; i/=2){
			st[i] = op(st[l(i)], st[r(i)]);
		}
	}
	void clear(){
		for(int i = 1; i < n<<1; i++){
			st[i] = neutral;
		}
	}
};

struct cmp{
	bool operator()(tuple<ll,ll,ll,ll> t1, tuple<ll,ll,ll,ll> t2){
		if(get<1>(t1) < get<1>(t2)) return true;
		else if(get<1>(t1) == get<1>(t2)) return get<3>(t1) < get<3>(t2);
		return false;
	}
};

ll countUseless(vector<tuple<ll, ll, ll> >& tuples) {
	typedef tuple<ll,ll,ll> tt;
	typedef tuple<ll,ll,ll,ll> TT;
	vector<TT> arr;

	sort(tuples.begin(), tuples.end(), [](tt t1, tt t2) -> bool {
		auto [x1, y1, z1] = t1;
		auto [x2, y2, z2] = t2;
		return y1 < y2;
		if(y1 < y2) return true;
		else if(y1 == y2) return x1 < x2;
		return false;
	});
	for(int i = 0; i < tuples.size(); i++)
		arr.push_back(tuple_cat(tuples[i], make_tuple(i)));
    
	sort(arr.begin(), arr.end());
	SegmentTree stc(arr.size()); stc.update(get<3>(arr[0]), get<2>(arr[0]));
	set<tuple<ll,ll,ll,ll>, cmp> s; s.insert(arr[0]);

	for(int i = 1; i < arr.size(); i++){
		bool elim = false;

		int aux = get<3>(arr[i]);
		get<3>(arr[i]) = -1;
		auto lit = s.upper_bound(arr[i]);
		get<3>(arr[i]) = 1e9;
		auto pit = s.upper_bound(arr[i]);
		get<3>(arr[i]) = aux;

		if(lit != s.begin() && stc.q(0, get<3>(*prev(lit))) <= get<2>(arr[i])) elim = true;
		if(pit != s.begin() && stc.q(0, get<3>(*prev(pit))) < get<2>(arr[i])) elim = true;
		
		if(!elim){
			s.insert(arr[i]);
			stc.update(get<3>(arr[i]), get<2>(arr[i]));
		}
	}

	arr.clear();
	for(auto e : s) arr.push_back(e);
	sort(arr.begin(), arr.end(), [&](TT t1, TT t2)->bool{
		auto [x1,y1,z1,p1] = t1;
		auto [x2,y2,z2,p2] = t2;
		if(z1 < z2) return true;
		else if(z1 == z2 && y1 < y2) return true;
		else if(z1 == z2 && y1 == y2 && x1 < x2) return true;
		else if(z1 == z2 && y1 == y2 && x1 == x2) return p1 < p2;
		return false;
	});

	stc.clear(); stc.update(get<3>(arr[0]), get<0>(arr[0]));
	s.clear(); s.insert(arr[0]);

	for(int i = 1; i < arr.size(); i++){
		bool elim = false;
		int aux = get<3>(arr[i]);
		get<3>(arr[i]) = -1;
		auto lit = s.upper_bound(arr[i]);
		get<3>(arr[i]) = 1e9;
		auto pit = s.upper_bound(arr[i]);
		get<3>(arr[i]) = aux;

		if(pit != s.begin() && stc.q(0, get<3>(*prev(pit))) < get<0>(arr[i])) elim = true;

		if(!elim){
			s.insert(arr[i]);
			stc.update(get<3>(arr[i]), get<0>(arr[i]));
		}
	}

    return s.size();
}

int main() {
    ll n, e;
    cin >> n >> e;
    vvpii g(n);
    vi dist0, dist1, dist2;

    for (ll i = 0; i < e; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    dijkstra(0, g, dist0);
    dijkstra(1, g, dist1);
    dijkstra(2, g, dist2);

    vector<tuple<ll,ll,ll> > ord(n);
    for (ll i = 0; i < n; i++) {
        get<0>(ord[i]) = dist0[i];
        get<1>(ord[i]) = dist1[i];
        get<2>(ord[i]) = dist2[i];
    }

    cout << countUseless(ord) << "\n";

    return 0;
}
