#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;
const ll LLINF = LLONG_MAX;

struct SegmentTree {
    vector<ll> st;
    ll n, neutral = 0; //elemento neutro de la operacion

    ll op(ll a, ll b){ //tipo de operacion
        return a^b;
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

    void update(ll node, ll val) { //point update
        st[n + node] = val;
        for (ll i = (n + node) >> 1; i >= 1; i >>= 1) {
            st[i] = op(st[l(i)], st[r(i)]);
        }
    }
};

void solve(){
    int n,q; cin >> n >> q;
    vi arr(n); 
    for(int i = 0; i < n; i++) cin >> arr[i];
    SegmentTree ST(arr);
    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        cout << ST.ROpQ(a,b) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}