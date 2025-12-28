#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = INT32_MAX;
const ll LLINF = 1e18;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << ' ' << arr[i];}cout << endl;}

int ini = 703472575;
int finGood = 1706989334;
int finBad = 1028344922;
int up1 = 678644412;
int up2 = 324872347;
int pro = 30235;

struct SegmentTree {
    //Para cambiar RANGE QUERIES entre incremento o sustitucion, cambiar donde ponga 'CAMBIO'
    //Para cambiar el tipo de operacion, cambiar donde ponga 'OPERACION'
    vector<ll> st, lazy;
    ll n, neutral = LLINF; //OPERACION

    ll op(ll a, ll b){ //OPERACION
        return min(a,b);
    }
    int l(int v) {return v << 1;}
    int r (int v) {return ((v << 1) + 1);}

    SegmentTree(vi A) {
        n = (ll)A.size();
        while (__builtin_popcount(n) != 1) {
            A.push_back(neutral);
            n++;
        }
        st.resize(n << 1);
        lazy.resize(n << 1);
        for (ll i = 0; i < n; i++)
            st[n + i] = A[i];
        for (ll i = n - 1; i >= 1; i--)
            st[i] = op( st[l(i)], st[r(i)] );
    }

    void propagate(int node, int L, int R){
        if(lazy[node]){
            st[node] += lazy[node]; //CAMBIO
            if(L != R){
                lazy[l(node)] += lazy[node]; //CAMBIO
                lazy[r(node)] += lazy[node]; //CAMBIO
            }
            lazy[node] = 0;
        }
    }

    ll ROpQ(int node, int L, int R, int ql, int qr) { //current node, maxLeft, maxRight, querieLeft, querieRight
        propagate(node, L, R);
        if (ql <= L && R <= qr)
            return st[node];
        if (L > qr || ql > R)
            return neutral;
        ll mid = (L + R) / 2;
        return op(ROpQ(l(node), L,mid,ql,qr) , ROpQ(r(node),mid+1,R,ql,qr));
    }
    ll ROpQ(int ql, int qr) { //querieLeft, querieRight
        return ROpQ(1, 0, n - 1, ql, qr);
    }

    void update(int node, int L, int R, int ql, int qr, ll val) { //current node, maxLeft, maxRight, querieLeft, querieRight
        propagate(node, L, R);
        if(ql <= L && R <= qr){
            lazy[node] += val; //CAMBIO
            propagate(node, L, R);
        }else if(L > qr || ql > R){
            return;
        }else{
            int mid = (L + R) / 2;
            update(l(node), L, mid, ql, qr, val);
            update(r(node), mid+1, R, ql, qr, val);
            st[node] = op(st[l(node)], st[r(node)]);
        }
    }
    void update(int ql, int qr, ll val){ update(1, 0, n-1, ql, qr, val); } //querieLeft, querieRight
};

void solve(){
    ll n,q; cin >> n >> q; vi arr(n); cin >> arr;
    SegmentTree ST(arr);

    while(q--){
        int a; cin >> a;
        if(a==1){
            int l,r,val; cin >> l >> r >> val; l--; r--;
            ST.update(l,r,val);
        }else{
            int k; cin >> k; k--;
            cout << ST.ROpQ(k,k) << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
