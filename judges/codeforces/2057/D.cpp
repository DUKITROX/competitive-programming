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
    vector<pair<int,int> > st, lazy;
    ll n;
    pair<int,int> neutral = {INF,-INF}; //OPERACION
    ll defecto = 0; // CAMBIO

    pair<int,int> op(pair<int,int> a, pair<int,int> b){ //OPERACION
        return {min(a.first,b.first), max(a.second,b.second)};
    }
    int l(int v) {return v << 1;}
    int r (int v) {return ((v << 1) + 1);}

    SegmentTree(vi& A) {
        n = (ll)A.size();
        while (__builtin_popcount(n) != 1) {
            n++;
        }
        st.resize(n << 1);
        for (ll i = 0; i < n; i++)
            st[n + i] = (i < A.size() ? make_pair(A[i],A[i]) : neutral);
        for (ll i = n - 1; i >= 1; i--)
            st[i] = op( st[l(i)], st[r(i)] );
    }

    pair<int,int> ROpQ(int node, int L, int R, int ql, int qr) { //current node, maxLeft, maxRight, querieLeft, querieRight
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

    void update(int ind, int val){
        st[n+ind] = {val,val};
        for(int i = (n+ind)/2; i > 0; i/=2){
            st[i] = op(st[i<<1], st[(i<<1)+1]);
        }
    }
};

void solve(){
    int n,q; cin >> n >> q;
    vector<int> arr(n); cin >> arr;
    SegmentTree st(arr);
    cout << st.ROpQ(0,n-1) << "\n";
    for(int i = 0; i < q; i++){
        int ind, val; cin >> ind >> val; ind--;
        st.update(ind,val);
        cout << st.ROpQ(0,n-1) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}
