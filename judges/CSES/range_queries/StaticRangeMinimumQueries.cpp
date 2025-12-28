using namespace std;
#include <bits/stdc++.h>

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;
const ll LLINF = LLONG_MAX;

struct SegmentTree {
	vector<ll> st;
	ll n, neutral = LLINF; //elemento neutro de la operacion

    ll op(ll a, ll b){ //tipo de operacion
        if(a < b)return a;
        else return b;
    }
    ll l(ll v) {return v << 1;}
    ll r (ll v) {return ((v << 1) + 1LL);}
    ll p(ll v) {return v >> 1;}

	SegmentTree(vi A) {
		n = (ll)A.size();
		while (__builtin_popcount(n) != 1) {
			A.push_back(neutral);
			n++;
		}
		st.resize(n << 1);
		for (ll i = 0; i < n; i++) // Añadimos las hojas
			st[n + i] = A[i];
		for (ll i = n - 1; i >= 1; i--) // Completamos el arbol
            st[i] = op( st[l(i)], st[r(i)] );
	}

    ll ROpQ(ll node, ll L, ll R, ll ql, ll qr) { //starting node, maxLeft, maxRight, querieLeft, querieRight
        if (ql <= L && R <= qr) //El llervalo analizado esta completamente dentro de la querie
            return st[node];
        if (L > qr || ql > R) //El llervalo analizado esta completamento fuera de la querie
            return neutral;
        ll mid = (L + R) / 2;
        return op(ROpQ(l(node),L,mid,ql,qr) , ROpQ(r(node),mid+1,R,ql,qr)); //El intervalo analizado esta parzialmente en la querie
	}
    long long ROpQ(ll l, ll r) { //querieLeft, querieRight
        return ROpQ(1, 0, n - 1, l, r);
	}

    void update(ll node, ll v) { //point update
        st[n + node] = v;
        for (ll i = (n + node) >> 1; i >= 1; i >>= 1) {
            st[i] = op(st[l(i)], st[r(i)]);
        }
    }
};

/*
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
*/

void solve(){
    ll n,q; cin >> n >> q;
    vi A(n);
    for(ll i = 0; i < n; i++) cin >> A[i];
    SegmentTree ST(A);
    //for(int i = 0; i < 2*n; i++)cout << i << " : " << ST.st[i] << "\n";
    for(int i = 0; i < q; i++){
        ll a,b; cin >> a >> b;a--;b--;
        cout << ST.ROpQ(a,b) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}