#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	string s1,s2; cin >> s1 >> s2;
	multiset<char> c1,c2;
	map<char,int> f;
	for(int i = 0; i < s1.length(); i++) c1.insert(s1[i]), f[s1[i]]++;
	for(int i = 0; i < s2.length(); i++) c2.insert(s2[i]);
	for(auto [a,b] : f){
		if(b > c2.count(a)){
			cout << "Impossible\n";
			return;
		}
	}
	for(auto e : s1)  c2.erase(c2.find(e));

	auto it1 = s1.begin(); auto it2 = c2.begin();
	while(it1 != s1.end() || it2 != c2.end()){
		if(it1 != s1.end() && it2 != c2.end()){
			if(*it1 <= *it2){
				cout << *it1++;
			}else{
				cout << *it2++;
			}
		}else if(it1 != s1.end()){
			cout << *it1++;
		}else{
			cout << *it2++;
		}
	}
	cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

