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

struct sparseTable{
    vvi stm,stM;
    int n,m;
    int lg2(int i){
        return 31 - __builtin_clz(i);
    }
    sparseTable(const vi& v) : n(v.size()), m(lg2(v.size())){
        stm.assign(m+1, vi(n));
        stM.assign(m+1, vi(n));
        for(int j = 0; j < n; j++) stm[0][j] = v[j];
        for(int j = 0; j < n; j++) stM[0][j] = v[j];
        for(int i = 1; i <= m; i++)
            for(int j = 0; j + (1 << i) <= n; j++){
                stm[i][j] = min(stm[i-1][j], stm[i-1][j + (1 << (i-1))]);
                stM[i][j] = max(stM[i-1][j], stM[i-1][j + (1 << (i-1))]);
            }
    }
    int querym(int L, int R){
        int i =  lg2(R-L+1);
        return min(stm[i][L], stm[i][R + 1 - (1 << i)]);
    }
    int queryM(int L, int R){
        int i =  lg2(R-L+1);
        return max(stM[i][L], stM[i][R + 1 - (1 << i)]);
    }
};

void solve(){
    int n; cin >> n; vi arr(n); cin >> arr;
    sparseTable SP(arr);
    int q; cin >> q;
    while(q--){
        int x,y; cin >> x >> y;
        double sol =  SP.querym(x,y) + ((double)(SP.queryM(x,y)-SP.querym(x,y))/(double)2);
        if(x) sol = max(sol, (double)(SP.queryM(0,x-1) + SP.querym(x,y)));
        if(y < n-1) sol = max(sol, (double)(SP.queryM(y+1, n-1) + SP.querym(x,y)));
        cout << sol << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(1);
    solve();
}