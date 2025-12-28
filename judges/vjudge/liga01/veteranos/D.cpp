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

struct sparseTable{
    vvi st;
    int n,m;
    int lg2(int i){
        return 31 - __builtin_clz(i);
    }
    sparseTable(const vi& v) : n(v.size()), m(lg2(v.size())){
        st.assign(m+1, vi(n));
        for(int j = 0; j < n; j++) st[0][j] = v[j];
        for(int i = 1; i <= m; i++)
            for(int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))]);
    }
    int query(int L, int R){
        int i =  lg2(R-L+1);
        return max(st[i][L], st[i][R + 1 - (1 << i)]);
    }
};

void solve(){
    int n; cin >> n; vi arr(n); cin >> arr; sparseTable st(arr);
    int sol = 0;
    for(int i = 1; i < n-1; i++){
        int l = st.query(0,i-1),r = st.query(i+1,n-1);
        if(l > arr[i] && arr[i] < r) sol = max(sol, min(l,r)-arr[i]);
    }
    cout << sol << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}