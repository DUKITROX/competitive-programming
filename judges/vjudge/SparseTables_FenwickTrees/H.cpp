#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

struct SegmentTree {
    //Para cambiar RANGE QUERIES entre incremento o sustitucion, cambiar donde ponga 'CAMBIO'
    //Para cambiar el tipo de operacion, cambiar donde ponga 'OPERACION'
    vector<ll> st, lazy;
    ll n, neutral = LLINF; //OPERACION
    ll defecto = -1; // CAMBIO

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
        lazy.resize(n << 1, defecto);
        for (ll i = 0; i < n; i++)
            st[n + i] = A[i];
        for (ll i = n - 1; i >= 1; i--)
            st[i] = op( st[l(i)], st[r(i)] );
    }

    void propagate(int node, int L, int R){
if(lazy[node] != defecto){
            st[node] += lazy[node]-defecto; //CAMBIO
            if(L != R){
                lazy[l(node)] += lazy[node]-defecto; //CAMBIO
                lazy[r(node)] += lazy[node]-defecto; //CAMBIO
            }
            lazy[node] = defecto;
        }
    }

    ll ROpQ(int node, int L, int R, int ql, int qr) { //current node, maxLeft, maxRight, querieLeft, querieRight
        propagate(node, L, R);
        if (ql <= L && R <= qr)
            return st[node];
        if (L > qr || ql > R)
            return neutral;
        ll mid = (L + R) / 2;
        return op(ROpQ(l(node), L, mid, ql, qr) , ROpQ(r(node), mid+1, R, ql, qr));
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
    void show(){
        for(int i = 0; i < 10; i++) cout << st[n+i] << " ";
        cout << " ";
    }
};

bool solve(){
    int q; if(cin >> q && !q) return false;
    vi arr(100000); SegmentTree ST(arr);
    while(q--){
        string s; cin >> s;
        if(s == "B") {
            int x,y,v; cin >> x >> y >> v; x--; y--;
            ST.update(x,y,v);
        }else{
            int x; cin >> x; x--;
            cout << ST.ROpQ(x,x) << "\n";
        }
    }
    return true;
}
/*
9
B 5 5 2
B 8 8 2
B 10 13 1
Q 8
B 8 13 1
Q 8
B 15 16 1
B 2 10 1
Q 8
9
B 5 5 2
B 8 8 2
B 10 13 1
Q 8
B 8 13 1
Q 8
B 15 16 1 B 2 10 1
Q 8
0
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve());
}