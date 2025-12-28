#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define int int64_t

void solve(){
	int n; cin >> n; if(!n) {cout << "0\n"; return;}
	vector<int> arr(n); for(int i = 0; i < n; i++) cin >> arr[i];
	reverse(arr.begin(), arr.end());

	int cont = 1, sol = arr[0], prev = arr[0], act;
	for(int i = 1; i < n; i++){
		act = arr[i];
		if(act < prev)
			cont++;
		else
			sol += act - prev;
		prev = act;
	}
	if(!prev) cont--;
	cout << cont + sol + 1 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	solve();
}

