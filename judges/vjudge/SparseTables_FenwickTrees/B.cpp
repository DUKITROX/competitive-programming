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
    ll n, neutral = -LLINF; //OPERACION

    ll op(ll a, ll b){ //OPERACION
        return max(a,b);
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
};

bool solve(){
    int n,q; cin >> n; if(!n) return false; cin >> q; vi arr(n); cin >> arr;
    vi ARR; map<int,int> m; map<int,pair<ll,ll> > M; int cont = 1; ll x,y;
    for(int i = 1; i < n; i++){
        if(arr[i-1] == arr[i]){
            cont++;
            M[arr[i]].second = i;
        }else{
            m[arr[i-1]] = ARR.size();
            M[arr[i]].first = M[arr[i]].second = i;
            ARR.push_back(cont);
            cont = 1;
        }
    }
    m[arr[n-1]] = ARR.size();
    ARR.push_back(cont);
    SegmentTree ST(ARR);
    for(int i = 0; i < q; i++){
        cin >> x >> y; x--; y--;
        ll sol = -LLINF;
        if(arr[x] == arr[y]){
            cout << y-x+1 << "\n";
            continue;
        }
        if(m[arr[x]] + 1 <= m[arr[y]] - 1) sol = max(sol, ST.ROpQ(m[arr[x]]+1, m[arr[y]]-1));
        //cout << m[arr[x]] + 1 << " " << m[arr[y]] - 1 << "\n";
        sol = max(sol, M[arr[x]].second - x + 1);
        sol = max(sol, y - M[arr[y]].first + 1);
        cout << sol << "\n";
    }
    return true;
}
/*
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10

5 5
1 1 1 2 2

0
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve());
}