#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

template<typename T> istream &operator>>(istream& is, vector<T>& v){for(int i = 0; i < v.size(); i++)is>>v[i];return is;}

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
                st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
    }
    int query(int L, int R){
        int i =  lg2(R-L+1);
        return min(st[i][L], st[i][R + 1 - (1 << i)]);
    }
};

void solve(){
    int n, cont = 0; cin >> n;
    map<int,int> m1;
    vi arr(n),a1(n),a2(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a; m1[a] = i; a1[i] = a;
    }
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = m1[a];
        a2[i] = a;
    }
    sparseTable st(arr);
    int b = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] > st.query(i,n-1)) b = i;
    }
    cout << b+1 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}