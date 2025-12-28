#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

void solve(){
	int n,q; cin >> n >> q;
	int a=0,b,M=INT_MIN,c;
	set<int> s;
	for(int i = 0; i < n; i++){cin >> b; a |= b; ckmax(M,b); s.insert(b);
		if(i==0)c=b;
		else c &= b;
	}
	for(int i = 0; i < q; i++){
		cin >> b;
		int A = a, B=(b>>1), MM=M,j=1,cont=0;
		int P = B;

		while(j <= b){
			if(!(A&j)) cont+=j, MM |= j;
			A |= j;
			P |= j;
			j <<= 1;
		}
		P++;
		if(n==1){
			cout << max(__builtin_popcount(A), __builtin_popcount(a+b)) << "\n";
		}else{
			b -= cont;
			if(M+b >= P) A |= P;
			//A |= A+b;
			cout << __builtin_popcount(A) << "\n";
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

