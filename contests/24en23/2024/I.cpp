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

int n,m; 
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool valid(vector<string>& mapa, ii act){
    if(act.first < 0 || act.first >= n || act.second < 0 || act.second >= m) return false;
    if(mapa[act.first][act.second] != '.') return false;
    return true;
}

void dfs(vector<string>& mapa, ii act){
    mapa[act.first][act.second] = 'O';
    for(int i = 0; i < 4; i++){
        ii sig = mp(act.first+dx[i], act.second+dy[i]);
        if(valid(mapa, sig)){
            dfs(mapa,sig);
        }
    }
}
/*
4 5
.X...
.XX..
..X..
.....
2 6
...X..
...X..
0 0
*/
bool solve(){
    cin >> n >> m; if(!n && !m) return false;
    vector<string> mapa(n); cin >> mapa;
    dfs(mapa,mp(0,0));
    cout << (mapa[0][0] == mapa[n-1][m-1] ? "SI" : "NO") << "\n";
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(solve());
}