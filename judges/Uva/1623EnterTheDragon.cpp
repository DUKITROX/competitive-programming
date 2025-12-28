#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
const int INF = 1e9+7;
const ll LLINF = LLONG_MAX;
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
void show(vi arr){for(int i = 0; i < arr.size(); i++){ cout << arr[i] << ' ';}cout << endl;}

void solve(){
    int n,m,a,cont=0; cin >> n >> m; vi prev(n+1,0); vi arr(m+1),sol(m+1,0);for(int i=1; i <=m; i++)cin>>arr[i];
    cont = 0;
    set<int> s;
    bool pos = true;
    for(int i = 1; i <= m; i++){
        a = arr[i];
        if(a){
            set<int>::iterator v = s.lower_bound(prev[a]);
            int p = *v;
            //cout << "A: " << a  << " P: " << p << endl;
            if(v != s.end() && p > prev[a]){
                sol[p] = a;
                prev[a] = i;
                s.erase(p);
            }else{
                pos = false;
            }
        }else{
            s.insert(i);
        }
    }
    if(pos){
        cout << "YES\n";
        //show(arr);show(sol);
        for(int i = 1; i <= m; i++){
            if(!arr[i]) cout << sol[i] << " ";
        }
        cout << "\n";
    }else cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--) solve();
}
/*
1 3 8
0 0 0 1 0 1 2 3

1 2 8
0 0 1 0 1 0 1 2

1 2 8
0 1 0 1 0 1 0 2

4
2 4
0 0 1 1
2 4
0 1 0 2
2 3
0 1 2
2 4
0 0 0 1
*/
