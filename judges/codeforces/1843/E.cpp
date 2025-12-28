#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;

struct SegmentTree {
	vector<long long> tree;
	int n;
	SegmentTree(vector<int> A) {
		n = (int)A.size();
		while (__builtin_popcount(n) != 1) {
			A.push_back(0);
			n++;
		}
		tree.resize(n << 1);
		for (int i = 0; i < n; i++)
			tree[n + i] = A[i];
		for (int i = n - 1; i >= 1; i--)
			tree[i] = tree[i << 1]+ tree[(i << 1) + 1];
	}
    int l(int v) {return v << 1;}
    int r (int v) {return (v << 1) + 1;}

    long long RSQ(int node, int L, int R, int ql, int qr) {
        if (ql <= L && R <= qr)
            return tree[node];
        if (L > qr || ql > R)
            return 0;
        int mid = (L + R) / 2;
        return RSQ(node << 1, L, mid, ql, qr) + RSQ((node << 1) + 1, mid + 1, R, ql, qr);
	}
    long long RSQ(int l, int r) {
        return RSQ(1, 0, n - 1, l, r);
	}
    void update(int node, int v) {
        tree[n + node] = v;
        for (int i = (n + node) >> 1; i >= 1; i >>= 1) {
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }
    }
};

bool calc(SegmentTree& ST, vii& sets, vi& queries, int m){
    bool ok = false;
    for(int i = 0; i <= m; i++) ST.update(queries[i], 1);
    for(int i = 0; i < sets.size(); i++){
        int a = ST.RSQ(sets[i].first, sets[i].second);
        int b = sets[i].second - sets[i].first + 1;
        b -= a;
        if(a > b) ok = true;
    }
    for(int i = 0; i <= m; i++) ST.update(queries[i], 0);
    return ok;
}

void solve(){
    int n, m; cin >> n >> m;
    vii sets(m);
    vi arr(n,0);
    for(int i = 0; i < m; i++){
        cin >> sets[i].first >> sets[i].second;
        sets[i].first--; sets[i].second--;
    }
    int q; cin >> q;
    vi queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
        queries[i]--;
    }

    SegmentTree ST(arr);
    int l = 0, r = q-1, mid, ans = -1;

    while(l <= r){
        mid = (l+r)/2;
        if(calc(ST, sets, queries, mid)){
            r = mid-1;
            ans = mid+1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}