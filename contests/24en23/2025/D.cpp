#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}


void solve(){
	auto mk = [&](const string& S){
		if (S.size() <= 2) 
			return S;
		string mid = S.substr(1, S.size()-2);
		sort(mid.begin(), mid.end());
		return string(1, S.front()) + mid + S.back();
	};

	map<string,string> m;
	set<string> can;

	string s; while(cin >> s && s != "."){
		string S = s;
		s = mk(S);
		auto it = m.find(s);

		if (it != m.end()) {
			if (it->second != S) {
				can.insert(s);  
			}
		} else {
			m[s] = S;
		}
	}
	while(cin >> s && s != "."){
		string S = s;
		s = mk(S);
		if(!can.count(s) && m.find(s) != m.end()) cout << m[s] << " ";
		else cout << S << " ";
	}
	cout << ".\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

