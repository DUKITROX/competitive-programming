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
int N,M,K,n;
int node(ii p){return p.first+p.second*(N+1);} 
double euclidDist(ii a, ii b){return sqrt(abs(a.first-b.first)*abs(a.first-b.first) + abs(a.second-b.second)*abs(a.second-b.second));}
void join(ii a, UFDS& f, set<ii>& s){
    for(int i = max(0,a.first-K); i <= min(N,a.first+K); i++){
        for(int j = max(0,a.second-K); j <= min(M,a.second+K); j++){
            ii b = mp(i,j);
            if (euclidDist(a,b) <= K && s.count(b)) f.merge(node(a), node(b));
        }
    }
}
string sol(ii p) {cout << p.first << " " << p.second;return "";}

bool solve(){
    cin >> N >> M >> K >> n;
    if(!cin) return false;
    UFDS f((N+1)*(M+1));
    vii arr(n); cin >> arr;
    set<ii> s;
    s.insert(mp(0,0));
    s.insert(mp(N,M));
    int i = n-1;
    while(f.find(node(mp(0,0))) != f.find(node(mp(N,M))) && i >= 0){
        join(arr[i],f,s);
        s.insert(arr[i]);
        i--;
    }
    cout << (f.find(node(mp(0,0))) == f.find(node(mp(N,M))) ? sol(arr[i+1]) : "NUNCA SE PUDO") << "\n";
    return true;
}
/*
3 3 2 4
1 1
2 2
2 0
3 1

3 3 2 2
3 0
0 3
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve());
}