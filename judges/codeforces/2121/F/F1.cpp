#include <bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<class T> istream& operator>>(istream& is, vector<T>& v) {for(auto& e : v) is >> e; return is;}
template<class T> ostream& operator<<(ostream& os, vector<T>& v) {for(auto& e : v) os << e << " "; return os;}

#define int int64_t

int n,s,x;
int count(int l, int r, const vector<int>& pref) {
    map<int, int> freq;
    freq[0] = 1;
    int count = 0;
    for (int i = l; i <= r; ++i) {
        int curr_sum = pref[i] - (l > 0 ? pref[l - 1] : 0);
        count += freq[curr_sum - s];
        freq[curr_sum]++;
    }
    return count;
}

void solve() {
    cin >> n >> s >> x;
    vector<int> arr(n); cin >> arr;
    vector<int> pref(n);
    pref[0] = arr[0];

    for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + arr[i];

    int res = 0;
    int i = 0;

    while (i < n) {
        if (arr[i] > x) i++;
		else{
			int j = i;
			while (j < n && arr[j] <= x) ++j;

			vector<int> seg(arr.begin() + i, arr.begin() + j);
			vector<int> segPref(seg.size());
			segPref[0] = seg[0];

			for (int k = 1; k < seg.size(); ++k)
				segPref[k] = segPref[k - 1] + seg[k];

			map<int, int> freq;
			freq[0] = 1;
			int total = 0, curr_sum = 0;

			for (int k = 0; k < seg.size(); ++k) {
				curr_sum += seg[k];
				total += freq[curr_sum - s];
				freq[curr_sum]++;
			}

			int wo_x = 0;
			int l = 0;
			for (int r = 0; r <= seg.size(); ++r) {
				if (r == seg.size() || seg[r] == x) {
					if (r > l) {
						map<int, int> f;
						f[0] = 1;
						int sum = 0;
						for (int t = l; t < r; ++t) {
							sum += seg[t];
							wo_x += f[sum - s];
							f[sum]++;
						}
					}
					l = r + 1;
				}
			}

			res += total - wo_x;
			i = j;
		}

    }

    cout << res << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;cin >> tt;while (tt--) solve();
}

