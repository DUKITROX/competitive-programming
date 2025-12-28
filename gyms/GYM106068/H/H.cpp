#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

template<typename T = int>
struct STree {
	using F = function<T(const T&, const T&)>;
	F f; vector<T> s; int n; T unit;
	STree(int n, F f = std::min, T def = INT_MAX) : s(2*n, def), n(n), f(f) , unit(def){}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve(){
	int n; cin >> n; vector<int> l(n),r(n); cin >> l; r = l;
	transform(l.begin(),l.end(),l.begin(),[&](const int& lux)->int{return (int)ceil(cbrt((double)lux));});
	transform(r.begin(),r.end(),r.begin(),[&](const int& rux)->int{return -(int)ceil(cbrt((double)rux));});
	for(int i = 0; i < n; i++) l[i] += i, r[i] += i;

	STree<pair<int,int>> lt(n,[](pair<int,int>p1,pair<int,int>p2){return min(p1,p2);},{INT_MAX,INT_MAX}); 
	STree<pair<int,int>> rt(n,[](pair<int,int>p1,pair<int,int>p2){return max(p1,p2);},{INT_MIN,INT_MIN});
	for(int i = 0; i < n; i++) lt.update(i,{l[i],i}) , rt.update(i,{r[i],i});

	int q; cin >> q; while(q--){
		int t; cin >> t; if(t==1){
			int i,v; cin >> i >> v; i--;
			lt.update(i,{i+(int)ceil(cbrt((double)v)),i});
			rt.update(i,{i-(int)ceil(cbrt((double)v)),i});
		}else{
			pair<int,int> res; int i; cin >> i; i--;
			if(i && (res = lt.query(0,i)).first <= i || i < n-1 && ( res = rt.query(i+1,n)).first >= i) cout << res.second+1 << "\n";
			else cout << "-1\n";
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

