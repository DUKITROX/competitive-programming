#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))
#define mp make_pair
typedef long long ll;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vector<ii> > vvii;
typedef vector<bool> vb;
const double EPS = 1e-9;
const ll INF = 1e9 + 7;
const ll LLINF = LLONG_MAX;
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1,T2> &p){is >> p.first >> p.second; return is;}
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1,T2> &p){os << p.first << " " << p.second; return os;}
template<typename T> istream &operator>>(istream &is, vector<T> &v){for(int i = 0; i < v.size(); i++) is >> v[i]; return is;}
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){for(int i = 0; i < v.size(); i++) os << v[i] << " "; return os;}
template<typename T1, typename T2> pair<T1,T2> operator+(const pair<T1,T2>& a, const pair<T1,T2>& b){return mp(a.first + b.first, a.second + b.second);}

struct UFDS{
    vector<ll> p,setSize;
    int numSets, N;
    UFDS(int n){
        N = n;
        p.assign(N,0);
        setSize.assign(N,1);
        numSets = N;
        for(int i = 0; i < N; i++) p[i] = i;
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
    void reset(){
        p.assign(N,0);
        setSize.assign(N,1);
        numSets = N;
        for(int i = 0; i < N; i++) p[i] = i;   
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ifstream f; f.open("casesA.txt");
    ofstream of; of.open("rA.txt");
    ll o = 0;
    while(f >> n && n){
        cout << ++o << endl;
        vector<ll> ed(n); vector<pair<ll,ll> > arr(n);
        for(int i = 0; i < n; i++){
            f >> ed[i];
            arr[i] = mp(ed[i],i);
        }
        sort(arr.begin(), arr.end(), greater<ii>());

        UFDS df(n);
        ll h = arr[0].first, j = 0;
        ll prev = 0, SOL = 0;
        while(j < n && h >= 2) {
            while(j < n && arr[j].first == h){   
                ll act = arr[j].second; 
                ll left = max(0LL, arr[j].second-1);
                ll right = min(n-1, arr[j].second+1);

                if(ed[left] >= h && df.find(left) != df.find(act)){
                    prev = (prev%INF + (df.size(act)*df.size(left))%INF)%INF;
                    df.merge(left, act);
                }
                if(ed[right] >= h && df.find(right) != df.find(act)){
                    prev = (prev%INF + (df.size(act)*df.size(right))%INF)%INF;
                    df.merge(right, act);
                }
                j++;
            }
            SOL = (SOL%INF + ((prev%INF) * (h-(j<n && arr[j].first > 0LL ? arr[j].first : 1LL))%INF)%INF)%INF;
            h = arr[j].first;
        }
        of << (SOL%INF) << "\n";
    }
    f.close(); of.close();
}
/*
4
2 3 2 1
4
2 3 3 2
0
*/