#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}
void die(string S){puts(S.c_str());exit(0);}

#define int int64_t

void solve(){
	int n,k; cin >> n >> k;
	if(k%2==1){
		for(int i = 0; i < k; i++) cout << n << " "; cout << "\n";
	}else{
		for(int i = 0; i < k-2; i++) cout << n << " "; 
		if(__builtin_popcount(n) == 1) cout << n << " 0\n";
		else{
			int a = 1; a <<= 34; int cont=0;
			while(cont < 2 && a > 0){
				if(a&n) cont++;
				a >>= 1;
			}
			if(a==0) cout << n << " 0\n";
			else{
				a <<= 1; a--;
				cout << (n|a) << " " << ((n|a) ^ n) << "\n";
			}
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

