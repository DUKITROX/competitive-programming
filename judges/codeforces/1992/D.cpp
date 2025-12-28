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

void solve(){
    int n,m,k;string s; cin >> n >> m >> k >> s; string S = 'L'+s+'L';
    vi irs; for(int i = 0; i < n+2; i++)if(S[i]!='W')irs.push_back(i);

    for(int i = 0; i < n+2; i++){
        if(S[i] == 'L'){
            int q=-1,w=-1;
            for(int j = 1; j <= m; j++){
                if(i+j >= n+1){
                    cout << "YES\n"; return;
                }else{
                    if(S[i+j] == 'L') q = i+j;
                    else if(S[i+j] == 'W') w = i+j;
                }
            }
            if(q!=-1){
                i = q-1;
                continue;
            }else if(w!=-1){
                i = w-1;
                continue;
            }else break;
        }else if(S[i] == 'W'){
            int ind = *upper_bound(irs.begin(), irs.end(), i);
            if(ind <= i+k){
                if(ind >= n+1){
                    cout << "YES\n";
                    return;
                }
                if(S[ind] == 'L'){
                    k -= (ind-i);
                    i = ind-1;
                    continue;   
                }else break;
            }else break;
        }
    }
    cout << "NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}