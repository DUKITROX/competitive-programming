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

void solve(int n){
    multiset<int> homo;
    set<int> het;
    while(n--){
        string s; int a; cin >> s >> a;
        if(s == "insert"){
            if(!het.count(a))
                het.insert(a);
            else
                homo.insert(a);
        }else{
            if(homo.count(a))
                homo.erase(a);
            else het.erase(a);
        }
        if(het.size() > 1 && homo.size())
            cout << "both\n";
        else if(het.size() > 1)
            cout << "hetero\n";
        else if(homo.size())
            cout << "homo\n";
        else
            cout << "neither\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; solve(n);
}