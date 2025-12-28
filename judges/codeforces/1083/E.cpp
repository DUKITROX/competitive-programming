#include <bits/stdc++.h>
using namespace std;
#define int long long 
typedef long long ll;

struct Line{
	mutable ll k, m , p;
	bool operator<(const Line& o) const {return k < o.k;}
	bool operator<(ll x) const {return p < x;}
};

struct Trie {
	int prefixes, words;
	vector<Trie*> child;
	Trie() : prefixes(0), words(0), child(26, nullptr) {}
	~Trie() { for(int i = 0; i < 26; i++) delete child[i]; }
	void add(string const& s, int i = 0) {
		++prefixes;
		if (i >= s.size()) ++words;
		else (child[s[i]-'a'] == nullptr ? child[s[i]-'a'] = new Trie() : child[s[i]-'a'])->add(s, i + 1);
	}
};

struct LineContainer : multiset<Line, less<> >{
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b){
		return a/b - ((a^b) < 0 && a%b);
	}
	bool isect (iterator x, iterator y){
		if(y == end()) return x->p = inf, false;
		if(x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k,m,0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
		    isect(x, erase(y));
    	}
	ll query(ll x){
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k*x + l.m;
	}
};

void solve (){
	int n,x,y,a; cin >> n;
	vector<pair<pair<int,int> ,int> > arr(n); 
	for(int i = 0; i < n; i++) 
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
	sort(arr.begin(), arr.end());
	
	ll sol = arr[0].first.first*arr[0].first.second - arr[0].second;
	LineContainer lc; lc.add(-arr[0].first.first, sol);

	for(int i = 1; i < n; i++){
		ll v = arr[i].first.first*arr[i].first.second -
		arr[i].second +
		lc.query(arr[i].first.second);

		lc.add(-arr[i].first.first,v);
		sol = max(sol,v);
	}
	cout << sol << "\n";
}

int32_t main(){
	solve();
}
