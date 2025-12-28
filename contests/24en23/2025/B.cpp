#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int f,c; while(cin >> f >> c, f || c){
		int R = 0, enc_lib = 0, enc_nec = 0;
		int sol = 0;

		for(int i = 0; i < f; i++){
			string s1,s2; cin >> s1 >> s2;
			for(int j = 0; j < c; j++){
				if(s2[j] == '1'){
					if(s1[j] == '1') continue;
					else if(s1[j] == '0') enc_nec++;
					else if(s1[j] == 'R') sol++;
				}else{
					if(s1[j] == '0') continue;
					else if(s1[j] == '1') enc_lib++;
					else R++;
				}
			}
		}
		if(enc_nec > enc_lib + R) cout << "IMPOSIBLE\n";
		else {
			if(enc_nec <= enc_lib) cout << sol + R + enc_lib << "\n";
			else cout << sol + enc_lib + R + enc_nec - enc_lib << "\n";
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

