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
    int n; cin >> n; string s1,s2; cin >> s1 >> s2;
    int i=0,j=n-1,a=n; vi sol; bool sh = false;
    while(a--){
        if(sh){
            if((s1[i]=='1'?'0':'1') == s2[a]){
                i++;
                continue;
            }else if((s1[j]=='1'?'0':'1') == s2[a]){
                sol.push_back(1);
                s1[j] = (s1[j]=='1'?'0':'1');
            }
            sol.push_back(j-i+1);
            j--;
            sh^=1;
        }else{
            if(s1[j] == s2[a]){
                j--;
                continue;
            }else if(s1[i] == s2[a]){
                sol.push_back(1);
                s1[i] = (s1[i]=='1'?'0':'1');
            }
            sol.push_back(j-i+1);
            i++;
            sh^=1;
        }
    }
    cout << sol.size() << " " << sol;
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}