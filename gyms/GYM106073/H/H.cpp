#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int uint64_t

int n,m;
int stom(const string& s){
	int ax=0;
	for(int j = 0; j < m; j++) 
		if(s[j] == '1')
			ax |= (1<<(m-j-1));
	return ax;
}

void solve(){
	cin >> n >> m;
	vector<int> a(1<<m);
	for(int i = 0; i < n; i++){
		string s; cin >> s; 
		a[stom(s)]++;
	}

	for(int i = 0; i < m; i++)
		for(int j = 0; j < (1<<m); j++)
			if(j&(1<<i))
				a[j] += a[j^(1<<i)];

	for(int j = 0; j < (1<<m); j++)
		a[j] = (a[j]*(a[j]-1)*(a[j]-2))/6;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < (1<<m); j++)
			if(j&(1<<i))
				a[j] -= a[j^(1<<i)];

	int q; cin >> q;
	for(int i = 0; i < q; i++){
		string s; cin >> s;
		cout << a[stom(s)] << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

