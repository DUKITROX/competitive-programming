#include <bits/stdc++.h>
using namespace std;

struct Tree{
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b){return max(a,b);}
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n){}
	void update (int pos, T val){
		for(s[pos+=n] = val; pos /= 2;)
			s[pos] = f(s[pos*2], s[pos*2+1]);
	}
	T query(int b, int e){
		T ra = unit, rb = unit;
		for(b += n, e += n; b < e; b/= 2, e/=2){
			if(b%2) ra = f(ra, s[b++]);
			if(e%2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve(){
	int n; cin >> n; vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];

	Tree st(n); for(int i = 0; i < n; i++) st.update(i, arr[i]);
	vector<int> mn(n), sol(n,-1); mn[n-1] = arr[n-1];
	for(int i = n-2; i >= 0; i--) mn[i] = min(mn[i+1], arr[i]);

	int cont=0;
	for(int i = 0; i < n;){
		int ind = i;
		while(true){
			int M = st.query(0,ind+1);
			int u = lower_bound(mn.begin(),mn.end(),M) - mn.begin() - 1;
			if(u<0)break;
			if(u == ind) break;
			ind = u;
		}
		cout << "ind: " << i << " " << ind << endl;
		assert(cont++<4);
		int val = st.query(0,ind+1);
		for(int j = i; j <= ind; j++) cout << val << " ";
		cout << endl;
		i = ind+1;
	}
	cout << "\n";
}

int main(){
	int t; cin >> t; while(t--) solve();
}
