#pragma GCC optimize ("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(){
	int n,k; cin >> n >> k;
	int dist = 0;
	set<int> sum;
	vector<int> a(n), b(n); 
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) {cin >> b[i]; dist += (b[i] == -1); if(b[i] != -1) sum.insert(a[i]+b[i]);}
	
	if(sum.size()>1) cout << "0\n";
	else if(sum.size() == 1 && dist == 0) cout << "1\n";
	else if(sum.size() == 1 && dist < n){
		if(*min_element(a.begin(), a.end()) + k < *sum.begin() || *max_element(a.begin(), a.end()) > *sum.begin()) cout << "0\n";
		else cout << "1\n";
	}else if(sum.size() == 0){
		if(*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) > k) cout << "0\n";
		else cout << *min_element(a.begin(), a.end()) + k + 1 - *max_element(a.begin(), a.end()) << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

