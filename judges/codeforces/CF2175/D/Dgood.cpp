#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

const int64_t NEG = -(1LL << 60);

void solve(){

	int n, k; cin >> n >> k;
	vector<int> a(n); cin >> a;

	vector<pair<int,int>> seg;
	int pref = 0,curCap=-1,start=0;
	for (int i = 0; i < n; i++) {
		pref = max(pref, a[i]);
		if (curCap == -1) {
			curCap = pref;
			start = 0;
		} else if (pref != curCap) {
			seg.push_back({curCap, i - start});
			curCap = pref;
			start = i;
		}
	}
	seg.push_back({curCap, n - start});

	int M = k+1, SZ = M*M;

	auto id = [&](int s, int m) { return s * M + m; };

	vector<int64_t> dp(SZ, NEG), ndp(SZ, NEG), bestLess(SZ, NEG);
	dp[id(0, 0)] = 0;

	for (auto [cap, len] : seg) {
		for (int s = 0; s <= k; s++) {
			int64_t mx = NEG;
			bestLess[id(s, 0)] = NEG;
			for (int m = 1; m <= k; m++) {
				mx = max(mx, dp[id(s, m - 1)]);
				bestLess[id(s, m)] = mx;
			}
		}
		fill(ndp.begin(), ndp.end(), NEG);
		for (int s = 0; s <= k; s++) {
			for (int m = 0; m <= k; m++) {
				int64_t v = dp[id(s, m)];
				if (v == NEG) continue;
				ndp[id(s, m)] = max(ndp[id(s, m)], v + 1LL * m * len);
			}
		}
		cap = min(cap, k);
		for (int x = 1; x <= cap; x++) {
			for (int s = x; s <= k; s++) {
				int64_t base = bestLess[id(s - x, x)]; // previous max < x
				if (base == NEG) continue;
				ndp[id(s, x)] = max(ndp[id(s, x)], base + 1LL * x * len);
			}
		}
		dp.swap(ndp);
	}
	int64_t ans = 0;
	for (int64_t v : dp) ans = max(ans, v);
	cout << ans << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int tt; cin >> tt; while(tt--) solve();
}

