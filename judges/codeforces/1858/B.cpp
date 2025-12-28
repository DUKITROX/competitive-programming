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
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 1; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

void solve(){
    int n,m,d; cin >> n >> m >> d;
    vi sellers(m+1); cin >> sellers; sellers[0] = 1;
    vector<ll> sums(m+1,0);
    ll res = 0, cont = 0, SUM = 0;
    for(int i = 0; i <= m; i++){
        int l = sellers[i],h;
        i==m? h=n : h = sellers[i+1]-1;
        int s = (h-l+1)/d;
        (h-l+1)%d ? s++ : s;
        sums[i] = s;
        SUM += s;
    }
    //show(sums);
    for(int i = 1; i <= m; i++){
        int l = sellers[i-1],h;
        i==m? h=n : h = sellers[i+1]-1;
        int s = (h-l+1)/d;
        (h-l+1)%d ? s++ : s;
        int r = sums[i-1]+sums[i] - s;
        if(r > res){
            res = r;
            cont = 1;
        }else if( r == res){
            cont++;
        }
    }
    cout << SUM-res << " " << cont << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}

/*
8
6 2 2
2 5
8 3 2
3 5 8
10 4 9
2 8 9 10
30 5 8
6 8 15 24 29
30 5 8
6 8 12 20 27
8 8 3
1 2 3 4 5 6 7 8
2 2 2
1 2
1000000000 3 20000000
57008429 66778899 837653445
*/
