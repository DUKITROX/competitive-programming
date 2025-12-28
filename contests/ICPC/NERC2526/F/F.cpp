#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n; cin >> n;
	vector<int> arr(n); cin >> arr;
	int un=0;
	for(auto e : arr)if(e==1)un++;
	//alice starts, so bob selects pile for alice and then she chooses how many to remove
	if(un==n){
		if(n%2) cout << "Alice\n";
		else cout << "Bob\n";
	}else{
		if(un%2) cout << "Bob\n";
		else cout << "Alice\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

