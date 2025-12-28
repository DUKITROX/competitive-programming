#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void chg(char& c){c = c == '0' ? '1' : '0';}

void solve(){
	int n; string s1, s2; cin >> n >> s1 >> s2;
	vector<pair<int,int>> fw, bw;

	int ok = 1;
	for(int i = 1; i < n; i++)  if(s1[i] == s1[i-1]) ok = 0;
	if(ok) fw.push_back({0,2}), chg(s1[0]), chg(s1[1]), chg(s1[2]);

	int l,r=-1;
	for(int i = 1; i < n && r==-1; i++) if(s1[i] == s1[i-1]) l=i-1, r=i;

	char color = s1[l];
	l--;r++;

	while(0 <= l || r < n){
		if(0 <= l){
			if(s1[l] != color) fw.push_back({l+1,r-1}), color = s1[l];
			l--;
		}
		if(r < n){
			if(s1[r] != color) fw.push_back({l+1, r-1}), color = s1[r];
			r++;
		}
	}
	if(color=='1') fw.push_back({0,n-1});
	 

	ok = 1;
	for(int i = 1; i < n; i++)  if(s2[i] == s2[i-1]) ok = 0;
	if(ok) bw.push_back({0,2}), chg(s2[0]), chg(s2[1]), chg(s2[2]);

	r=-1;
	for(int i = 1; i < n && r==-1; i++) if(s2[i] == s2[i-1]) l=i-1, r=i;

	color = s2[l];
	l--;r++;
	while(0 <= l || r < n){
		if(0 <= l){
			if(s2[l] != color) bw.push_back({l+1,r-1}), color = s2[l];
			l--;
		}
		if(r < n){
			if(s2[r] != color) bw.push_back({l+1, r-1}), color = s2[r];
			r++;
		}
	}
	//cout << color << " color" << endl;
	if(color=='1') bw.push_back({0,n-1});
	reverse(bw.begin(),bw.end());

	cout << fw.size() + bw.size() << "\n";
	for(int i = 0; i < (int)fw.size(); i++) cout << fw[i].first+1 << " " << fw[i].second+1 << "\n";
	for(int i = 0; i < (int)bw.size(); i++) cout << bw[i].first+1 << " " << bw[i].second+1 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

