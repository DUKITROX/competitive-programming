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

ll dp(vvi& adj, vector<ll>& dmg, int i, vector<vector<ll> >& memo, vi& deg, vector<bool>& vis, vi& p){
    vis[i] = true;
    if(memo[i][0] != -1) return max(memo[i][0], memo[i][1]);
    if(deg[i] == 1){
        memo[i][1] = dmg[i];
        memo[i][0] = 0;
        return dmg[i];
    }
    memo[i][1] = dmg[i];
    memo[i][0] = 0;
    for(int v : adj[i]){
        if(v != p[i]){
            p[v] = i;
            memo[i][0] += dp(adj,dmg,v,memo,deg,vis,p);
            memo[i][1] += memo[v][0];
        }
    }
    return max(memo[i][0], memo[i][1]);
}
//Find minimum non negative (mex>=0) element that is not included in the array
class MEX {
private:
    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;
public:
    MEX(vector<int> const& A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }
    int mex() {
        return *missing_numbers.begin();
    }
    void update(int idx, int new_value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};
/*
2
5
47 15 32 29 23
1 2
1 3
2 4
2 5
*/
void solve(){
    int n; cin >> n;vector<ll> dmg(n); cin >> dmg;
    if(n == 1) {cout << dmg[0] << "\n";return;}
    if (n == 2){int a,b; cin >> a >> b;cout << dmg[0]+dmg[1]+min(dmg[0],dmg[1]) << "\n"; return;}
    vvi adj(n);
    vi deg(n,0);
    int s = 0;
    ll sol = 0; for(ll v : dmg) sol += v;
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b; a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++; deg[b]++;
        if(deg[a]>1) s = a;
        else if(deg[b]>1) s = b;
    }
    vector<vector<ll> > memo(n,vector<ll>(2,-1));
    vector<bool> vis(n,false);
    vi p(n); p[s] = -1;
    ll M = dp(adj, dmg, s, memo, deg, vis,p);
    cout << M << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}