#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T, class U> istream& operator>>(istream& is, pair<T,U>& p) {is >> p.first >> p.second; return is;}
template<class T, class U> ostream& operator<<(ostream& os, pair<T,U>& p) {os << "(" << p.first << ", " << p.second << ") "; return os;}
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

struct Line {
	mutable int k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(int x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const int inf = (int)1e18;
	int div(int a, int b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(int k, int m) { //k*x + m
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	int query(int x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

void solve(){
	int n; cin >> n;
	vector<pair<int,int>> aux(n), arr; cin >> aux;
	sort(aux.begin(), aux.end(), greater<>());
	int M = INT_MIN; for(int i = 0; i < n; i++) if(ckmax(M, aux[i].second)) arr.push_back(aux[i]); n = (int)arr.size();

	vector<int> dp(n); 
	LineContainer cvx; cvx.add(-arr[0].first,0);
	for(int i = 0; i < n; i++){
		dp[i] = -cvx.query(arr[i].second);
		if(i < n-1) cvx.add(-arr[i+1].first,-dp[i]);
	}
	cout << dp.back() << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

