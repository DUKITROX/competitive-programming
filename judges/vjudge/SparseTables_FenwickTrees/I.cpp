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
    ll n, neutral = 1; //OPERACION
    ll defecto = -INF; // CAMBIO

    ll op(ll a, ll b){ //OPERACION
        return a*b;
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
            st[node] = lazy[node]; //CAMBIO
            if(L != R){
                lazy[l(node)] = lazy[node]; //CAMBIO
                lazy[r(node)] = lazy[node]; //CAMBIO
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
            lazy[node] = val; //CAMBIO
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
        for(int i = 0; i < n; i++) cout << st[n+i] << " ";
        cout << " ";
    }
};

bool solve(){
    int n,q; cin >> n; if(!cin) return false; cin >> q; vi arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 0) arr[i] = -1;
        else if(arr[i] == 0) arr[i] = 0;
        else arr[i] = 1;
    }
    SegmentTree ST(arr);
    char c; int x,y;
    while(q-- && cin >> c >> x >> y){
        if(c == 'C'){
            if(y < 0) y = -1;
            else if (y == 0) y = 0;
            else y = 1;
            ST.update(x-1,x-1,y);
        }else{
            if(!ST.ROpQ(x-1,y-1)) cout << "0";
            else if(ST.ROpQ(x-1,y-1) > 0) cout << "+";
            else cout << "-";
        }
    }
    cout << "\n";
    return true;
}
/*
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4

5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve());
}