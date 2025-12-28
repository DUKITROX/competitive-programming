#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n; cin >> n; 
	string s; getline(cin,s);

	for(int i = 0; i < n; i++){
		string s; getline(cin,s);
		stringstream ss(s);
		int a;
		int pos=0,time=0;
		while(ss >> a){
			if(a>0) pos++;
			else if(a<0) pos--;
			time += abs(a);
			if(!a) time++;
		}
		cout << pos << " " << time << endl;
	}
}
