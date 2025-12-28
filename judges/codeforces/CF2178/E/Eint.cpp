#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}
void die(string S){puts(S.c_str());exit(0);}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<int>(a, b)(rng) 
#define urd(a,b) uniform_real_distribution<double>(a, b)(rng)

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cout << "1" << endl;
	int k = uid(3,8);
	vector<int> a = {(1<<k)};
	vector<int> b = {(1<<k)};
	int stps = uid(4,7);
	for(int i = 0; i < stps; i++){
		int op = uid(0,1);
		if(op){
			a.insert(a.end(), b.begin(), b.end());
			b = a;
		}else{
			int side = uid(0,1);
			if(side && *max_element(a.begin(), a.end()) > 1) {
				auto it = max_element(a.begin(), a.end());
				int v = *it;
				it = a.erase(it);
				it = a.insert(it, v/2);
				a.insert(it, v/2);
			}else if(*max_element(b.begin(), b.end()) > 1){
				auto it = max_element(b.begin(), b.end());
				int v = *it;
				it = b.erase(it);
				it = b.insert(it, v/2);
				b.insert(it, v/2);
			}
		}
	}
	cout << a.size() << endl;
	while(1){
		char c; cin >> c; if(c == '?'){
			int l,r; cin >> l >> r;
			int sum = 0;
			for(int i = l-1; i < r; i++) sum += a[i];
			cout << sum << endl;
		}else{
			int m; cin >> m;
			if(m != *max_element(a.begin(), a.end())) {
				cout << "array(a): " << a << endl;
				cout << "predicit: " << m << endl;
				cout << "solution: " << *max_element(a.begin(), a.end()) << endl;
			}else{
				cout << "OK" << endl;
			}
			break;
		}
	}
}

