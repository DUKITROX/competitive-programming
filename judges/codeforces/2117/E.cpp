#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n; cin >> n;
	set<int> s;
	vector<int> A(n), B(n);
	for(int i = 0; i < n; i++)cin >> A[i];
	for(int i = 0; i < n; i++)cin >> B[i];

	if(A[n-1] == B[n-1]) {cout << n << "\n"; return;}
	if(A[n-1] == A[n-2] || B[n-1] == B[n-2] || A[n-2] == B[n-2]) {cout << n-1 << "\n"; return;}

	for(int i = n-1; i < n; i++) s.insert(A[i]), s.insert(B[i]);
	for(int i = n-3; i >= 0; i--){
		if(A[i] == A[i+1] || B[i] == B[i+1] || s.count(A[i]) || s.count(B[i]) || A[i] == B[i]) {cout << i+1 << "\n"; return;}
		s.insert(A[i+1]);
		s.insert(B[i+1]);
	}
	cout << 0 << endl;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

