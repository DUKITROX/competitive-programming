#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define mp make_pair
#define sort(x) sort(x.begin(), x.end())
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.first >> p.second; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.first << " " << p.second; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

struct SegmentTree {
    //Para cambiar RANGE QUERIES entre incremento o sustitucion, cambiar donde ponga 'CAMBIO'
    //Para cambiar el tipo de operacion, cambiar donde ponga 'OPERACION'
    vector<ll> st, lazy;
    ll n, neutral = -INF; //OPERACION
    ll defecto = 0; // CAMBIO

    ll op(ll a, ll b){ //OPERACION
        return max(a,b);
    }
    int l(int v) {return v << 1;}
    int r (int v) {return ((v << 1) + 1);}

    SegmentTree(vi& A) {
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
            st[node] += lazy[node]; //CAMBIO
            if(L != R){
                lazy[l(node)] += lazy[node]; //CAMBIO
                lazy[r(node)] += lazy[node]; //CAMBIO
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
    void show(){for(int i = 0; i < n; i++) cout << ROpQ(i,i) << " "; cout << "\n";}
};

void solve(){
    int n,k; cin >> n >> k; vi arr(n),a(k+1); SegmentTree st(a); cin >> arr; ll M,ind=0;
    for(int i = 0; i < n; i++){
        M = st.ROpQ(0,k);
        st.update(0,k,arr[i]);
        st.update(ind,ind,M-st.ROpQ(ind,ind));
        ind = (!ind?ind=k:--ind);
    }
    cout << st.ROpQ(0,k) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}