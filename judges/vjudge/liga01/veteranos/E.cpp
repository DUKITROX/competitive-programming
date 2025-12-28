#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define mp make_pair
#define sort(x) sort(x.begin(), x.end())
typedef long long ll;
typedef pair<long double,long double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
const long double EPS = 1e-7;
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.first >> p.second; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.first << " " << p.second; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

long double euclidDist(ii a, ii b){return sqrtl(abs(a.first-b.first)*abs(a.first-b.first) + abs(a.second-b.second)*abs(a.second-b.second));}
struct UFDS{
    vector<ll> p,setSize;
    int numSets;
    UFDS(int n){
        p.assign(n,0);
        setSize.assign(n,1);
        numSets = n;
        for(int i = 0; i < n; i++) p[i] = i;
    }
    int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
    void merge(int x, int y){
        int i = find(x); int j = find(y);
        if(i==j) return;
        p[i] = j;
        setSize[j] += setSize[i];
        numSets--;
    }
    int size(int i) {return setSize[find(i)];}
};

long double w;
bool check(UFDS& ds, vector<pair<pair<double,double>,double> >& arr, double r){
    if(r*2 > w) return false;
    for(int i = 0; i < arr.size(); i++){
        if(euclidDist(arr[i].first, mp(0,arr[i].first.second)) - 2*r - arr[i].second < 0.0) ds.merge(i, arr.size());
        if(euclidDist(arr[i].first, mp(w,arr[i].first.second)) - 2*r - arr[i].second < 0.0) ds.merge(i, arr.size()+1);
        for(int j = i+1; j < arr.size(); j++)
            if(euclidDist(arr[i].first, arr[j].first) - 2*r - arr[i].second - arr[j].second < 0.0) ds.merge(i,j);
    }
    return (ds.find(arr.size()) != ds.find(arr.size()+1));
}

void solve(){
    int n; cin >> w >> n;
    vector<pair<pair<double,double>,double> > arr(n); cin >> arr;
    double l=0.0, r=w, sol = w/2.0;
    int cont = 0;
    while(abs(r-l) > EPS){
        double m = (r+l)/2.0; cont++;
        UFDS ds(arr.size()+2);
        if(check(ds, arr, m)) l = sol = m;
        else r = m;
    }
    cout << setprecision(6) << fixed << sol << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}
/*
3
10
2
2 0 3
7 12 4

10
2
2 0 3
7 8 4

10
2
2 0 3
7 4 4
*/
