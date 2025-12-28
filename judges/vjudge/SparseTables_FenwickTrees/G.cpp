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

struct FenwickTree{
    vector<ll> ft;
    FenwickTree(int m){
        ft.assign(m+1, 0);
    }
    ll rsq(ll j){ 
        ll sum = 0;
        for(; j; j -= LSOne(j))
            sum += ft[ j ];
        return sum;
    }
    ll rsq(ll i, ll j){
        return rsq( j ) - rsq( i - 1 );
    }
    void update(ll i, ll v){
        for(; i < ft.size(); i += LSOne(i)){
            ft[ i ] += v;
        }
    }
};

void dfs(vvi &arr, vi &rank, vi& val, int u, FenwickTree &FT, vector<ll> &sol){
    ll prev = FT.rsq(0,rank[u]-1);
    for(auto &v : arr[u]) dfs(arr,rank,val,v,FT,sol);
    FT.update(rank[u], val[u]);
    sol[u] = FT.rsq(1,rank[u]-1) - prev;
}

void solve(){
    int n; cin >> n; vvi arr; vi rank(n), val(n); vector<ll> sol(n);
    int root;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a >> rank[i] >> val[i];
        if(a != -1)arr[a-1].push_back(i);
        else root = i;
    }
    FenwickTree FT(1000000);
    dfs(arr,rank,val,root,FT,sol);
    for(int i = 0; i < n; i++) cout << sol[i] << "\n";

}
/*
3
2 4 4
3 4 4
-1 10 10

5
4 4 80
1 1 40
-1 10 60
3 5 50
4 8 70

5
2 1 1
3 1 1
4 1 1
5 1 1
-1 1 1

5
2 1 1
3 2 1
4 3 1
5 4 1
-1 5 1

4
2 4 10
3 4 10
4 5 10
-1 6 10
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
