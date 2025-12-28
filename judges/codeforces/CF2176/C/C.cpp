#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n; cin >> n;
	multiset<int,greater<int>> odd,eve;
	int sum2 = 0;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		if(a%2) odd.insert(a);
		else eve.insert(a), sum2 += a;
	}

	if(odd.empty()){
		for(int i = 0; i < n; i++) cout << "0 "; cout << "\n"; return;
	}else{
		int sum = *odd.begin(); cout << sum << " ";

		int tmp = (eve.empty() ? sum2 : *prev(eve.end()));

		for(auto e : eve){
			sum += e;
			cout << sum <<" ";
		}
		sum2 = sum;
		if(!eve.empty())
			sum2 -= *prev(eve.end());

		for(int i = (int)eve.size() + 1; i < n; i++){
			if((i - (int)eve.size())%2 == 0) cout << sum << " ";
			else{
				if(i==n-1) cout << "0 ";
				else if(!eve.empty()) cout << sum2 << " ";
				else cout << "0 ";
			}
		}
		cout << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

