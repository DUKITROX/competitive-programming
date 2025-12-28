
#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

void solve(){
	int n; cin >> n;
	vector<vector<int>> arr(2, vector<int>(n)); cin >> arr[0] >> arr[1];
	vector<int> a(n), b(n); cin >> a >> b;

	vector<pair<int,int>> ops;
	for (int i = 0; i < n; i++) {
		int wantA = i + 1, wantB = i+1+n, pos=-1;
		for (int j = 0; j < n; j++) {
			if (a[j] == wantA) {
				pos = j;
				break;
			}
			if (b[j] == wantA) {
				pos = j;
				ops.emplace_back(3, j+1);
				swap(a[j], b[j]);
				break;
			}
		}
		for (int j = pos; j > i; j--) {
			ops.emplace_back(1, j);
			swap(a[j-1], a[j]);
		}

		pos = -1;
		for (int j = 0; j < n; j++) {
			if (b[j] == wantB) {
				pos = j;
				break;
			}
			if (a[j] == wantB) {
				pos = j;
				ops.emplace_back(3, j+1);
				swap(a[j], b[j]);
				break;
			}
		}
		for (int j = pos; j > i; j--) {
			ops.emplace_back(2, j);
			swap(b[j-1], b[j]);
		}
	}
	cout << ops.size() << "\n";
	for (auto &op : ops) {
		cout << op.first << " " << op.second << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}
