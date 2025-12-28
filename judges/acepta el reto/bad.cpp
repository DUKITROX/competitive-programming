#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; while(cin >> n && n){
		set<int> s;
		vector<int> res;
		while(!s.count(n)){
			assert(n>0);
			s.insert(n);
			res.push_back(n);
			int r = 0;
			while(n){
				r += (n%10)*(n%10)*(n%10);
				n/=10;
			}
			n = r;
		}
		for(int i = 0; i < (int)res.size()-1; i++) cout << res[i] << " - ";
		if(res.back() == 1)	cout << "1 -> cubifinito.\n";
		else cout << res.back() << " - " << res.back() << " -> no cubifinito.\n";
	}
}
