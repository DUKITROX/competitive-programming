#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define f first
#define s second
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
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.f >> p.s; return is;};
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.f << " " << p.s; return os;};
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}

bool solve(){
    int n; cin >> n; if(!n)return false; vi arr(n); cin >> arr; sort(arr);
    int f = 1; vii v;
    for(int i = 0; i < n; i++){
        if(arr[i] != arr[i-1]){
            v.push_back(mp(f,arr[i-1]));
            f = 1;
        }else f++;
    }
    v.push_back(mp(f,arr[n-1]));
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve());
}