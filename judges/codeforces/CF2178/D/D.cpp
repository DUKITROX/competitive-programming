#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}
void die(string S){puts(S.c_str());exit(0);}

#define int int64_t

void solve(){
	int n,m; cin >> n >> m;
	vector<pair<int,int>> arr(n);
	int S=0,H=0;
	for(int i = 0; i < n; i++){
		cin >> arr[i].first;
		arr[i].second = i+1;
	}
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++){
		if(i!=n-1) S += arr[i].first;
		else H += arr[i].first;
	}
	if(m*2 > n) {cout << "-1\n"; return;}

	vector<pair<int,int>> sol;

	if(m==0){
		if(S < H) {cout << "-1\n"; return;}
		int i;
		for(i = 0; i < n-2; i++){
			if(arr[i].first >= H) break;
			sol.push_back({arr[i].second, arr.back().second});
			H -= arr[i].first;
		}
		for(++i; i < n; i++)
			sol.push_back({arr[i].second, arr[i-1].second});
	}else{
		for(int i = 1; i <= n - 2*m; i++) sol.push_back({arr[i].second, arr[i-1].second});
		int p = n-2*m; // ultimo vivo
		for(int i = 0; i < m; i++) sol.push_back({arr[p+m+i].second, arr[p+i].second});
	}

	cout << sol.size() << "\n";
	for(auto [f,s] : sol) cout << f << " " << s << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

