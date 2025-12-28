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
    int merge(int x, int y){
        int i = find(x); int j = find(y);
        if(i==j) return 1;
        p[i] = j;
        setSize[j] += setSize[i];
        numSets--; return 1;
    }
    int size(int i) {return setSize[find(i)];}
};

void solve(){
    int n; cin >> n; UFDS f(n);
    int a = 1,b = -1;
    for(int i = 2; i <= n; i++){
        int s1=0,s2=0,s3=0;
        cout << "? " << a << " " << i << endl; cout.flush(); cin >> s1; if(s1==-1) return;
        cout << "? " << i << " " << a << endl; cout.flush(); cin >> s2; if(s2==-1) return;
        if(s1&&s2) f.merge(a,i);
        else if(!s1&&!s2) (b==-1?b=i:f.merge(b,i));
        else{
            if(i==2){
                cout << "? 2 3" << endl; cout.flush(); cin >> s1; if(s1==-1) return;
                cout << "? 3 2" << endl; cout.flush(); cin >> s2; if(s2==-1) return;
                if(s1==s2) --i;
            }
            cout << "! " << i << endl; cout.flush();
            break;
        }
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while(t--)solve();
}